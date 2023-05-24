from hybrid_example.Ising_lib import MonteCarloCpp

class MonteCarlo:
    def __init__(self, J:float, nx:int, ny:int):
        self.__monte_carlo_cpp = MonteCarloCpp(J, nx, ny)
        self.__J = J
        self.__T = 0
        self.__energy = 0
        self.__Cv = 0
        self.__num_flip = 0
        self.__num_relax = 0
        self.__num_count = 0

    @property
    def J(self) -> float:
        return self.__J
    @J.setter
    def J(self, J):
        self.__monte_carlo_cpp.J = J
        self.__J = J

    @property
    def T(self) -> float:
        return self.__T
    @T.setter
    def T(self, T):
        self.__monte_carlo_cpp.T = T
        self.__T = T

    @property
    def energy(self) -> float:
        return self.__energy

    @property
    def Cv(self) -> float:
        return self.__Cv

    @property
    def num_flip(self) -> int:
        return self.__num_flip
    @num_flip.setter
    def num_flip(self, num_flip):
        self.__monte_carlo_cpp.num_flip = num_flip
        self.__num_flip = num_flip

    @property
    def num_count(self) -> int:
        return self.__num_count
    @num_count.setter
    def num_count(self, num_count):
        self.__monte_carlo_cpp.num_count = num_count
        self.__num_count = num_count

    @property
    def num_relax(self) -> int:
        return self.__num_relax
    @num_relax.setter
    def num_relax(self, num_relax):
        self.__monte_carlo_cpp.num_relax = num_relax
        self.__num_relax = num_relax

    def Run(self):
        self.__monte_carlo_cpp.Run()
        self.__energy = self.__monte_carlo_cpp.energy
        self.__Cv = self.__monte_carlo_cpp.Cv
        return self.energy, self.Cv
