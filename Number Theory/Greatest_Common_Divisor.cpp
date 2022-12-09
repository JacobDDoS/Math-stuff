#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

typedef mp::cpp_dec_float_50 float50;

//Example Input
/*

58248912613462 31054712799198


15876000 370440000
*/

mp::cpp_int gcd(mp::cpp_int a, mp::cpp_int b) {
    if (b==0) {
        return a;
    } else {
        return gcd(b%a, a);
    }
}

int main() {
    mp::cpp_int a, b; cin >> a >> b;
    cout << gcd(a, b) << endl;
}