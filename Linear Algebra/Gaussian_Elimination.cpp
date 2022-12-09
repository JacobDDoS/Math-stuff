#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

typedef mp::cpp_dec_float_50 float50;

// Example Input
/*
3
3
4 -3 1 -8
-2 1 -3 -4
1 -1 2 3
*/

void gaussElimination() {
    int numberOfVariables, numberOfEquations;
    cout << "Enter the number of variables: ";
    cin >> numberOfVariables;
    cout << "Enter the number of equations: ";
    cin >> numberOfEquations;


    vector<vector<float50>> matrix; 
    for (int i=0;i<numberOfEquations;i++) {
        vector<float50> equation(numberOfVariables+1);
        cout << "(Equation) Enter the coefficients of your variables and the number the equation is equal to: ";
        for (int j=0;j<numberOfVariables+1;j++) {
            cin >> equation[j];
        }
        matrix.push_back(equation);
    }

    //Iterate through the equations, starting with the second one (this assumes that it is going to reduce top to bottom w/o switching rows)
    for (int i=1;i<numberOfEquations;i++) {
        vector<float50> equationToReduce = matrix[i];
        for (int j=0;j<i;j++) {
            if (equationToReduce[j] != 0) {
                float50 leadingVar = matrix[j][j];
                leadingVar *= -1;

                float50 scalar = leadingVar / equationToReduce[j];

                //Multiply the equation by the scalar so that the leading variable will eliminate when added with the equation before it
                vector<float50> newEquationAfterReduction;
                for (int k=0;k<equationToReduce.size();k++) {
                    newEquationAfterReduction.push_back(equationToReduce[k]*scalar);
                }

                //Add the equation to the next equation (To make the leading variable)
                for (int k=0;k<newEquationAfterReduction.size();k++) {
                    newEquationAfterReduction[k] += matrix[j][k];
                }

                equationToReduce = newEquationAfterReduction;
            }
        }
        matrix[i] = equationToReduce;
    }

    for (int i=0;i<matrix.size();i++) {
        for (auto num : matrix[i]) {
            cout << num << " ";
        }
        cout << endl;
    }

}

int main() {
    gaussElimination();
}