#include "EquationParser.hpp"


EquationParser::EquationParser() {}

vector<string> EquationParser::splitByDelimiter(const string& expression, char delimiter) {
    vector<string> tokens;
    stringstream ss(expression);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}