#include "EquationParser.hpp" 

int main(int ac, char* av[]) {
    
    if (ac != 2)
        throw invalid_argument("Invalid argument: There should be two arguments.");
    EquationParser equationParser;
    string leftSide, rightSide;
    unordered_map<int, double> powerCoefficientMap = equationParser.run(av[1]);
    // for (auto it: powerCoefficientMap) {
    //     cout << it.first << " " << it.second << endl;
    // }
}