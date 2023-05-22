#ifndef HYBRID_PROGRAMMING_ISING_HPP
#define HYBRID_PROGRAMMING_ISING_HPP
#include <iostream>
#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>

template <class T>
using Vector2d = std::vector<std::vector<T>>;

const double one_over_KB = 11.60450501;

class Lattice2d{
public:
    Vector2d<int> spin;
    Lattice2d(){}
    Lattice2d(int nx, int ny) {
        auto vector1d = std::vector<int>(nx, 1);
        this->spin = Vector2d<int>(ny, vector1d);
        this->max_index_x_ = nx-1;
        this->max_index_y_ = ny-1;
    }

    std::tuple<int, int, int, int> neighbors(int ix, int iy) {
        if(ix == 0) {
            if(iy == 0) {
                return {this->max_index_x_, ix+1, this->max_index_y_, iy+1};
            } else if(iy == this->max_index_y_) {
                return {this->max_index_x_, ix+1, iy-1, 0};
            } else {
                return {this->max_index_x_, ix+1, iy-1, iy+1};
            }
        } else if(ix == this->max_index_x_) {
            if(iy == 0) {
                return {ix-1, 0, this->max_index_y_, iy+1};
            } else if(iy == this->max_index_y_) {
                return {ix-1, 0, iy-1, 0};
            } else {
                return {ix-1, 0, iy-1, iy+1};
            }
        } else {
            if(iy == 0) {
                return {ix-1, ix+1, this->max_index_y_, iy+1};
            } else if(iy == this->max_index_y_) {
                return {ix-1, ix+1, iy-1, 0};
            } else {
                return {ix-1, ix+1, iy-1, iy+1};
            }
        }
    }

private:
    int max_index_x_ = -1;
    int max_index_y_ = -1;
};

class MonteCarlo {
public:
    int num_flip = 0;
    int num_relax = 0;
    int num_count = 0;
    Lattice2d lattice;
    double energy = 0;
    double Cv = 0;

    MonteCarlo(double J, int nx, int ny) {
        this->nx_ = nx;
        this->ny_ = ny;
        this->lattice = Lattice2d(nx, ny);
        this->SetJ(J);
    }

    double GetJ();
    double GetT();
    int SetJ(double J);
    int SetT(double T);
    int Run();

private:
    double J_ = 0;
    double T_ = 0; //temperature
    double current_energy_ = 0;
    double total_energy_ = 0;
    double total_energy_square_ = 0;
    int nx_ = 0;
    int ny_ = 0;
    double kEnergy_positive_4_ = 0;
    double kEnergy_positive_2_ = 0;
    double kEnergy_0_ = 0;
    double kEnergy_negative_2_ = 0;
    double kEnergy_negative_4_ = 0;
    double kP_positive_4_ = 0;
    double kP_positive_2_ = 0;
    double kP_0_ = 0;
    double kP_negative_2_ = 0;
    double kP_negative_4_ = 0;

    double CalculateEnergy();
    int MonteCarloStep();
    int Flip(int x, int y);
    std::tuple<double, double> EnergyAndProbability(int spin_sum);
    std::tuple<int, int> RandomSite();
    double RandomFloat();
};

double MonteCarlo::GetJ() {return this->J_;}
double MonteCarlo::GetT() {return this->T_;}

int MonteCarlo::SetJ(double J) {
    this->J_ = J;
    this->kEnergy_positive_4_ = -8*this->J_;
    this->kEnergy_positive_2_ = -4*this->J_;
    this->kEnergy_0_ = 0;
    this->kEnergy_negative_2_ = 4*this->J_;
    this->kEnergy_negative_4_ = 8*this->J_;
    this->current_energy_ = CalculateEnergy();
    this->SetT(this->T_);
    return 0;
}

int MonteCarlo::SetT(double T) {
    this->T_ = T;
    double one_over_T = 1.0/T;
    this->kP_positive_4_ = exp(-this->kEnergy_positive_4_ * one_over_KB * one_over_T);
    this->kP_positive_2_ = exp(-this->kEnergy_positive_2_ * one_over_KB * one_over_T);
    this->kP_0_ = exp(-this->kEnergy_0_ * one_over_KB * one_over_T);
    this->kP_negative_2_ = exp(-this->kEnergy_negative_2_ * one_over_KB * one_over_T);
    this->kP_negative_4_ = exp(-this->kEnergy_negative_4_ * one_over_KB * one_over_T);
    return 0;
}

int MonteCarlo::Run() {
    for(int i=0; i<this->num_relax; i++) {
        this->MonteCarloStep();
    }
    for(int i=0; i<this->num_count; i++) {
        this->MonteCarloStep();
        this->total_energy_ += this->current_energy_;
        this->total_energy_square_ += this->current_energy_ * this->current_energy_;
    }

    this->energy = this->total_energy_ / (this->nx_ * this->ny_ * this->num_count);
    this->Cv = (this->total_energy_square_ * this->num_count - this->total_energy_ * this->total_energy_) *
            one_over_KB /
            (this->nx_ * this->ny_ * this->T_ * this->T_ * this->num_count * this->num_count);
    return 0;
}

double MonteCarlo::CalculateEnergy() {
    this->current_energy_ = 0;
    int x_previous, x_next, y_previous, y_next;
    for(int ix=0; ix<this->nx_; ix++) {
        for(int iy=0; iy<this->ny_; iy++) {
            std::tie(x_previous, x_next, y_previous, y_next) = this->lattice.neighbors(ix, iy);
            this->current_energy_ += 0.5 * this->J_ * this->lattice.spin[ix][iy] * this->lattice.spin[x_previous][iy];
            this->current_energy_ += 0.5 * this->J_ * this->lattice.spin[ix][iy] * this->lattice.spin[x_next][iy];
            this->current_energy_ += 0.5 * this->J_ * this->lattice.spin[ix][iy] * this->lattice.spin[ix][y_previous];
            this->current_energy_ += 0.5 * this->J_ * this->lattice.spin[ix][iy] * this->lattice.spin[ix][y_next];
        }
    }
    return this->current_energy_;
}

int MonteCarlo::MonteCarloStep() {
    int x, y;
    for(int i=0; i<this->num_flip; i++) {
        std::tie(x, y) = RandomSite();
        this->Flip(x, y);
    }
    return 0;
}

std::tuple<double, double> MonteCarlo::EnergyAndProbability(int spin_sum) {
    if(spin_sum == 4) {
        return {this->kEnergy_positive_4_, this->kP_positive_4_};
    } else if(spin_sum == 2) {
        return {this->kEnergy_positive_2_, this->kP_positive_2_};
    } else if(spin_sum == 0) {
        return {this->kEnergy_0_, this->kP_0_};
    } else if(spin_sum == -2) {
        return {this->kEnergy_negative_2_, this->kP_negative_2_};
    } else if(spin_sum == -4) {
        return {this->kEnergy_negative_4_, this->kP_negative_4_};
    } else {
        throw std::out_of_range("Unknown value of spin summation.");
    }
}

int MonteCarlo::Flip(int x, int y) {
    auto[x_previous, x_next, y_previous, y_next] = this->lattice.neighbors(x, y);
    int spin_sum =
            this->lattice.spin[x_previous][y] +
            this->lattice.spin[x_next][y] +
            this->lattice.spin[x][y_previous] +
            this->lattice.spin[x][y_next];
    spin_sum *= this->lattice.spin[x][y];

    try {
        auto[delta_energy, probability] = this->EnergyAndProbability(spin_sum);
        if( this->RandomFloat() < probability) {
            this->lattice.spin[x][y] *= -1;
            this->current_energy_ += delta_energy;
        }
    } catch(std::out_of_range & err) {
        std::cerr << err.what() << std::endl;
        exit(-1);
    }
    return 0;
}

std::tuple<int, int> MonteCarlo::RandomSite() {
    static std::random_device rd;
    static std::mt19937 engine(rd());
    static std::uniform_int_distribution<int> int_distribution_x(0, this->nx_-1);
    static std::uniform_int_distribution<int> int_distribution_y(0, this->ny_-1);
    return {int_distribution_x(engine), int_distribution_y(engine)};
}

double MonteCarlo::RandomFloat() {
    static std::random_device rd;
    static std::mt19937  engine(rd());
    static std::uniform_real_distribution<double> float_distribution(0, 1);
    return float_distribution(engine);
}

#endif //HYBRID_PROGRAMMING_ISING_HPP