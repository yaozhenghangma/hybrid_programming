#ifndef HYBRID_PROGRAMMING_EXAMPLE
#define HYBRID_PROGRAMMING_EXAMPLE
#include <vector>
#include <iostream>

class my_vector{
public:
    std::vector<double> vector;

    my_vector(double element1, double element2) {
        this->vector.push_back(element1);
        this->vector.push_back(element2);
    }

    double function(){
        for(int i=0; i<size(this->vector); i++) {
            std::cout << this->vector[i] << std::endl;
        }
        return 1.0;
    }
};
#endif //HYBRID_PROGRAMMING_EXAMPLE
