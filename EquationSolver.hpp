#ifndef EQUATIONSOLVER_HPP
#define EQUATIONSOLVER_HPP

#include <unordered_map>
#include <iostream>

class EquationSolver {
private:
    int equationDegree;
    std::unordered_map<int, double> equation;

    void printReducedForm();

    void printSolution();

public:

    EquationSolver(const std::unordered_map<int, double>& equation);
    void run();

};;

#endif