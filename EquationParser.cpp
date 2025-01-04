#include "EquationParser.hpp"


EquationParser::EquationParser() {}

unordered_map<int, double> EquationParser::run(const string &equation) {

    string leftHandSide, rightHandSide;

    this->equationTrimmer(equation, leftHandSide, rightHandSide);
    leftHandSide = (leftHandSide[0] == '-') ? "0" + leftHandSide : leftHandSide;
    rightHandSide = (rightHandSide[0] == '-') ? "0" + rightHandSide : rightHandSide;
    this->parseSide(rightHandSide, RIGHT_SIDE);
    this->parseSide(leftHandSide, LEFT_SIDE);

    return (this->powerCoefficientMap);
}


double EquationParser::defineExpressionSign(string &expressionPart, bool &isRightSide) {

    expressionPart = trim(expressionPart);
    if (expressionPart.empty())
        return 0.0;

    double sign = 1.0;
    if (expressionPart[0] == '-') {
        sign = -1.0;
        expressionPart = trim(expressionPart.substr(1));
    }
    sign = isRightSide ? -sign : sign;
    return (sign);

}



pair<int, double> EquationParser::getExpressionValues(vector<string> &elements, double &sign) {

    pair<int, double> powerCoefficient(0, stod(this->trim(elements[0])) * sign);

    if (elements.size() > 1) {
        string element = trim(elements[1]);
        if (element.substr(0, 2) == "X^")
            powerCoefficient.first = stoi(element.substr(2));
    }

    return (powerCoefficient);
}

void EquationParser::parseExpressionPart(string &expressionPart, bool &isRightSide) {

    double sign = this->defineExpressionSign(expressionPart, isRightSide);
    vector<string> elements = this->splitByDelimiter(expressionPart, MULTIPLY);
    if (elements.empty())
        return;
    pair<int, double> powerCoefficient = this->getExpressionValues(elements, sign);
    this->powerCoefficientMap[powerCoefficient.first] += powerCoefficient.second;
    
}

void EquationParser::parseSide(const string &equationPart, bool isRightSide) {

    vector<string> expressions = this->splitByDelimiter(equationPart, PLUS);
    for (string expression: expressions) {
        vector<string> expressionParts = this->splitByDelimiter(expression, MINUS);
        for (size_t i = 0; i < expressionParts.size(); i++) {
            string expressionPart = expressionParts[i];
            if (expressionPart.empty())
                continue;
            if (i > 0)
                expressionPart = "-" + expressionPart;
            this->parseExpressionPart(expressionPart, isRightSide);
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

void EquationParser::equationTrimmer(const string &equation, string &leftHandSide, string &rightHandSide) {

    size_t dilimiterPosition = equation.find(EQUAL);
    if (dilimiterPosition == string::npos)
        throw invalid_argument("Invalid argument: Equation should have an equal sign");

    leftHandSide =  trim(equation.substr(0, dilimiterPosition));
    rightHandSide = trim(equation.substr(dilimiterPosition + 1));
}