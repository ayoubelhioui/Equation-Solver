#include "EquationParser/EquationParser.hpp" 

int main(int ac, char* av[]) {
    
    if (ac != 2)
        throw invalid_argument("Invalid number of arguments.");
    EquationParser equationParser;
    string leftSide, rightSide;
    vector<string> result = equationParser.splitByDelimiter(av[1], '=');
    for (string str: result) {
        cout << str << endl;
    }
}