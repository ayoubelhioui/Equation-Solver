
#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include <string>
#include <unordered_map>
#include <map>
#include <sstream>
#include <iostream>
#include <pair>
#include <vector>
#define PLUS '+'
#define MINUS '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define EQUAL '='


using namespace std;
class EquationParser {

    public:
        EquationParser();
        unordered_map<int, double> run(const string &equation);

    private:
        unordered_map<int, double> powerCoefficientMap;

        unordered_map<int, double> run(const string &equation);
        void equationTrimmer(const string &leftHandSide, const string &rightHandSide);
        vector<string> splitByDelimiter(const string& expression, char delimiter);
        string trim(const string& str);
        void parseRightHandSide(const string &rightHandSide);
        double defineExpressionSign(string &expressionPart);
        int getExpressiontValues(vector<string> &elements, double &sign);

};

#endif 

/*
    map<int, double> parse(const string& equation) {
        size_t equalPos = equation.find('=');
        if (equalPos == string::npos)
            throw invalid_argument("Invalid equation format");

        string leftSide = trim(equation.substr(0, equalPos));
        string rightSide = trim(equation.substr(equalPos + 1));

        if (leftSide[0] == '-')
            leftSide = "0" + leftSide;
        if (rightSide[0] == '-')
            rightSide = "0" + rightSide;

        vector<string> leftTerms = split(leftSide, '+');
        for (size_t i = 0; i < leftTerms.size(); i++) {
            vector<string> subTerms = split(leftTerms[i], '-');
            for (size_t j = 0; j < subTerms.size(); j++)
                if (!subTerms[j].empty()) {
                    if (j == 0)
                        parseTerm(subTerms[j]);
                    else
                        parseTerm("-" + subTerms[j]);
                }
        }

        vector<string> rightTerms = split(rightSide, '+');
        for (size_t i = 0; i < rightTerms.size(); i++) {
            vector<string> subTerms = split(rightTerms[i], '-');
            for (size_t j = 0; j < subTerms.size(); j++)
                if (!subTerms[j].empty()) {
                    if (j == 0)
                        parseTerm(subTerms[j], true);
                    else
                        parseTerm("-" + subTerms[j], true);
                }
        }

        cout << "---------------" << endl;
        for (auto it: coefficients) {
            cout << it.first << " "  << it.second << endl;
        }

        return coefficients;
    }

*/
