#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

typedef mp::cpp_dec_float_50 float50;
using mp::cpp_int;

//Example Input
/*

803 154

*/

void LinearCombinationsToGetGCD(cpp_int a, cpp_int b) {
    if (a < 0) {
        a *= -1;
    }
    if (b < 0) {
        b *= -1;
    }
    cpp_int copyA = a;
    cpp_int copyB = b;
    map<cpp_int, pair<cpp_int, cpp_int>> linearCombinationToGetNumber;
    linearCombinationToGetNumber[a] = make_pair(1, 0);
    linearCombinationToGetNumber[b] = make_pair(0, 1);

    if (b > a) {
        swap(b, a);
    }
    while (b != 0) {
        cpp_int quotient = a / b;
        cpp_int remainder = a % b;

        pair<cpp_int, cpp_int> linearCombinationToCreateNum = linearCombinationToGetNumber[a];
        pair<cpp_int, cpp_int> linearCombinationToCreateB = linearCombinationToGetNumber[b];
        linearCombinationToCreateNum.first -= linearCombinationToCreateB.first * quotient;
        linearCombinationToCreateNum.second -= linearCombinationToCreateB.second * quotient;

        linearCombinationToGetNumber[remainder] = linearCombinationToCreateNum;

        swap(a, b);
        b %= a;

    }

    pair<cpp_int, cpp_int> linearCombinationAnswer = linearCombinationToGetNumber[a];

    cout << "Greatest Common Divisor: " << a << endl;
    cout << linearCombinationAnswer.first << " " << linearCombinationAnswer.second << endl;
    cout << linearCombinationAnswer.first << " * " << copyA << " + " << linearCombinationAnswer.second << " * " << copyB << " = " << a << endl;
}


int main() {
    cpp_int a, b;
    cin >> a >> b;
    LinearCombinationsToGetGCD(a, b);
}