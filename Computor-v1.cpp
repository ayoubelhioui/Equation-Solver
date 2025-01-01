#include "EquationParser.hpp" 

int main(int ac, char* av[]) {
    
    if (ac != 2)
        throw invalid_argument("Invalid argument: There should be two arguments.");
    EquationParser equationParser;
    string leftSide, rightSide;
    vector<string> result = equationParser.run()
}