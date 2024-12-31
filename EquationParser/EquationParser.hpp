
#ifndef EQUATIONPARSER_H
#define EQUATIONPARSER_H

#include <string>
#include <map>
#include <iostream>


using namespace std;
class EquationParser {

    public:
        EquationParser();
        void splitEquation(const std::string& equation, std::string& leftSide, std::string& rightSide); 
    private:

};

#endif 
