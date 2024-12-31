
#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include <string>
#include <map>
#include <sstream>
#include <iostream>
#include <vector>


using namespace std;
class EquationParser {

    public:
        EquationParser();
        vector<string> splitByDelimiter(const string& expression, char delimiter);
        string trim();
    private:

};

#endif 
