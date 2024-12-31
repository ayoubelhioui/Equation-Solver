#include "EquationParser/EquationParser.hpp" 

int main(int ac, char* av[]) {
    EquationParser equationParser;
    string leftSide, rightSide;
    vector<string> result = equationParser.splitByDelimiter(av[1], '=');
    for (string str: result) {
        cout << str << endl;
    }
}