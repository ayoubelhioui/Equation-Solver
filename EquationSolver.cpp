#include "EquationSolver.hpp"



EquationSolver::EquationSolver(const std::unordered_map<int, double>& equation) : equation(equation) {

    this->equationDegree = 0;
    for (const auto& [key, value] : equation) {
        if (key > this->equationDegree)
            this->equationDegree = key;
    }

}

void EquationSolver::run() {
    this->printReducedForm();
}
void EquationSolver::printReducedForm() {

    std::cout << "Reduced form: ";
    bool first = true;
    for (int i = equationDegree; i >= 0; --i) {
        auto it = equation.find(i);
        if (it != equation.end()) {
            double coefficient = it->second;
            if (!first) {
                if (coefficient >= 0) {
                    std::cout << " + ";
                } else {
                    std::cout << " - ";
                    coefficient = -coefficient;
                }
            }
            if (i == 0) {
                std::cout << coefficient;
            } else if (i == 1) {
                std::cout << coefficient << " * X";
            } else {
                std::cout << coefficient << " * X^" << i;
            }
            first = false;
        }
    }
    std::cout << " = 0" << std::endl;
}

void EquationSolver::printSolution() {

}