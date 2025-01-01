#include "EquationParser.hpp"


EquationParser::EquationParser() {}

unordered_map<int, double> run(const string &equation) {

    unordered_map<int, double> result;
    string leftHandSide, rightHandSide;
    this->equationTrimmer(leftHandSide, rightHandSide);
    this->parseRightHandSide(rightHandSide);
    this->parseRightHandSide(rightHandSide);

    return (result);
}


double EquationParser::defineExpressionSign(string &expressionPart) {
    expressionPart = trim(expressionPart);
    if (expressionPart.empty())
        return;

    double sign = 1.0;
    if (expressionPart[0] == '-') {
        sign = -1.0;
        expressionPart = trim(expressionPart.substr(1));
    }
    if (isRightSide)
        sign = -sign;
    return (sign);
}



pair<int, double> EquationParser::getExpressionValues(vector<string> &elements, double &sign) {

    pair<int, double> powerCoefficient(1, stod(trim(elements[0])) * sign);

    if (elements.size() > 1) {
        string element = trim(elements[1]);
        if (element.substr(0, 2) == "X^")
            powerCoefficient.first = stoi(element.substr(2));
    }

    return (powerCoefficient)
}

void parseExpressionPart(string &expressionPart) {

    double sign = this->defineExpressionSign(expressionPart);
    vector<string> elements = split(expressionPart, MULTIPLY);
    if (parts.empty())
        return;
    pair<int, double> powerCoefficient = this->getExpressionValues(elements, sign);

    this->powerCoefficientMap.insert(powerCoefficient);
}

void parseSide(const string &equationPart, bool &isRightSide) {
    vector<string> expressions = split(equationPart, PLUS);
    for (string expression: expressions) {
        vector<string> expressionParts = split(expression, MINUS);
        for (string expressionPart: expressionParts)
            if (!expressionParts.empty()) {
                if (j == 0)
                    parseTerm(expressionParts);
                else
                    parseTerm("-" + expressionParts);
            }
    }
}

vector<string> EquationParser::splitByDelimiter(const string& expression, char delimiter) {

    vector<string> tokens;
    stringstream ss(expression);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string EquationParser::trim(const string& str) {

    size_t start = str.find_first_not_of(" \t\n\r\f\v");
    if (start == string::npos)
        return "";
    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    return str.substr(start, end - start + 1);

}

void EquationParser::equationTrimmer(const string &leftHandSide, const string &rightHandSide) {

    size_t dilimiterPosition = equation.find(EQUAL);
    if (equalPos == string::npos)
        throw invalid_argument("Invalid argument: Equation should have an equal sign");

    leftHandSide =  trim(equation.substr(0, dilimiterPosition));
    rightHandSide = trim(equation.substr(dilimiterPosition + 1));
}

