#ifndef EQUATIONSOLVER_HPP
#define EQUATIONSOLVER_HPP

#include <unordered_map>
#include <iostream>

using namespace std;
class EquationSolver {
private:
    int equationDegree;
    std::unordered_map<int, double> powerCoefficientMap;

    void printReducedForm();
    void printPolynomialDegree();
    void printSolution();
    void handleFirstDegree();
    void handleSecondDegree();
    void sqrt(double value);

public:

    EquationSolver(const std::unordered_map<int, double>& powerCoefficientMap);
    void run();

};;

#endif