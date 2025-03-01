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
    this->solvePolynomialEquation();

}

void EquationSolver::solvePolynomialEquation() {

    if (this->equationDegree == 0) {
        if (this->powerCoefficientMap[0] == 0)
            cout << "All real numbers are solutions." << endl;
        else
            cout << "No solution." << endl;
    }
    else if (this->equationDegree == 1)
        this->solveFirstDegree();
    else if (this->equationDegree == 2)
        this->solveSecondDegree();
    else
        throw invalid_argument("The polynomial degree is stricly greater than 2, I can't solve.");

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


void EquationSolver::solveFirstDegree() {

    cout << "The solution is:" << endl;
    double solution = (-1 * this->powerCoefficientMap[0]) / this->powerCoefficientMap[1];
    cout << solution << endl;

}

double  EquationSolver::sqrt(double &value) {
    if (value < 0)
        return (-1);
    double start = 0, end = value, precision = 0.0000001, med = (start + end) / 2;

    while (end - start > precision) {
        med = (start + end) / 2;
        if (med * med > value)
            end = med;
        else if (med * med < value)
            start = med;
        else 
        {

            return (med);
        }
    }

    return ((start + end) / 2);
}

void EquationSolver::solveSecondDegree() {

    double a = this->powerCoefficientMap[equationDegree];
    double b = this->powerCoefficientMap[equationDegree - 1];
    double c = this->powerCoefficientMap[equationDegree - 2];
    double discriminant = (b * b) - (4 * a * c);

    if (discriminant == 0) {
        cout << "The solution is: " << endl;
        double solution = (-b) / (2 * a);
        cout << "One real root: X = " << solution << endl;

    }
    else if (discriminant > 0) {
        double firstSolution = (-b + this->sqrt(discriminant)) / (2 * a);
        double secondSolution = (-b - this->sqrt(discriminant)) / (2 * a);

        cout << "Discriminant is strictly positive, the two solutions are: " << endl;
        cout << secondSolution << endl;
        cout << firstSolution << endl;
    }
    else {
        cout << "Discriminant is strictly negative, the two complex solutions are:" << endl;
        discriminant *= -1;
        cout << (b * -1) / (2 * a) << " - i * " << this->sqrt(discriminant) / (2 * a) << endl;
        cout << (b * -1) / (2 * a) << " + i * " << this->sqrt(discriminant) / (2 * a) << endl; 
    }
    
}
