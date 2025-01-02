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
    this->printPolynomialDegree();
}

void EquationSolver::printPolynomialDegree() {
    cout << "Polynomial degree: " << this->equationDegree << endl;
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


void EquationSolver::handleFirstDegree() {
    cout << "The solution is:" << endl;
    double solution = (-1 * this->powerCoefficientMap[0]) / this->powerCoefficientMap[1];
    cout << solution << endl;
}


// double EquationSolver::calculateDiscriminant() {

//     return (discriminant);
// }

void EquationSolver::sqrt(double value) {

}

void EquationSolver::handleSecondDegree() {

    double a = this->powerCoefficientMap[equationDegree];
    double b = this->powerCoefficientMap[equationDegree - 1];
    double c = this->powerCoefficientMap[equationDegree - 2];
    double discriminant = b * b - 4 * a * c;

    if (discriminant == 0) {
        cout << "The solution is: ";
        double solution = (-b) / (2 * a);
        cout << "One real root: X = " << solution << endl;

    }
    else if (discriminant > 0) {

        double firstSolution = (-b + sqrt(discriminant)) / (2 * a);
        double secondSolution = (-b - sqrt(discriminant)) / (2 * a);

        cout << "Discriminant is strictly positive, the two solutions are: " << endl;
        cout << firstSolution << endl;
        cout << secondSolution << endl;
    }
    
}

void EquationSolver::printSolution() {}