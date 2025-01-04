#include "EquationParser.hpp" 
#include "EquationSolver.hpp" 

int main(int ac, char* av[]) {
    
    try {
        
        if (ac != 2)
            throw (invalid_argument("Invalid argument: There should be two arguments."));

        EquationParser equationParser;
        string equation = av[1];
        unordered_map<int, double> powerCoefficientMap = equationParser.run(equation);

        EquationSolver equationSolver(powerCoefficientMap);
        equationSolver.run();

    }
    catch (exception &e) {
        cout << e.what() << endl;
    }
}