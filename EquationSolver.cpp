#include "EquationSolver.hpp"



EquationSolver::EquationSolver(const std::unordered_map<int, double>& powerCoefficientMap) : powerCoefficientMap(powerCoefficientMap) {

    this->equationDegree = 0;
    for (const auto& [key, value] : powerCoefficientMap) {
        if (key > this->equationDegree)
            this->equationDegree = key;
    }

}

void EquationSolver::run() {
    this->printReducedForm();
}

void EquationSolver::printReducedForm() {

    std::cout << "Reduced form: ";
    string expressionSign;
    for (int i = 0; i <= this->equationDegree; i++) {
        if (i == 0) {
            if (this->powerCoefficientMap[i] < 0)
                expressionSign = "-";
        }
        else {
            if (this->powerCoefficientMap[i] < 0)
                expressionSign = " - ";
            else
                expressionSign = " + ";
        }
        cout << expressionSign << abs(powerCoefficientMap[i]) << " * X^" << i;
    }
    std::cout << " = 0" << std::endl;
}

void EquationSolver::printSolution() {

}