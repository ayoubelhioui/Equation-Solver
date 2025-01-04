
#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include <string>
#include <unordered_map>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#define PLUS '+'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define EQUAL '='
#define RIGHT_SIDE true
#define LEFT_SIDE false

using namespace std;
class EquationParser {

    public:

        EquationParser();
        unordered_map<int, double> run(const string &equation);

    private:

        unordered_map<int, double> powerCoefficientMap;
        void equationTrimmer(const string &equation, string &leftHandSide, string &rightHandSide);
        vector<string> splitByDelimiter(const string& expression, char delimiter);
        void parseSide(const string &equationPart, bool isRightSide);
        string trim(const string& str);
        void parseRightHandSide(const string &rightHandSide);
        double defineExpressionSign(string &expressionPart, bool &isRightSide);
        pair<int, double> getExpressionValues(vector<string> &elements, double &sign);
        void parseExpressionPart(string &expressionPart, bool &isRightSide);

};

#endif 