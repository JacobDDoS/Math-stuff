#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/special_functions/bernoulli.hpp>
#include <bits/stdc++.h>
namespace mp = boost::multiprecision;
using namespace std;

typedef mp::cpp_dec_float_50 float50;
using mp::cpp_int;

// namespace boost { namespace math {

// template <class T>
// T bernoulli_b2n(const int n);  // Single Bernoulli number (default policy).

// template <class T, class Policy>
// T bernoulli_b2n(const int n, const Policy &pol); // User policy for errors etc.

// }} // namespaces


int main() {
   std::cout << "boost::math::max_bernoulli_b2n<float>::value = "  << boost::math::max_bernoulli_b2n<float>::value << std::endl;
   std::cout << "Maximum Bernoulli number using float is " << boost::math::bernoulli_b2n<float>( boost::math::max_bernoulli_b2n<float>::value) << std::endl;
   std::cout << "boost::math::max_bernoulli_b2n<double>::value = "  << boost::math::max_bernoulli_b2n<double>::value << std::endl;
   std::cout << "Maximum Bernoulli number using double is " << boost::math::bernoulli_b2n<double>( boost::math::max_bernoulli_b2n<double>::value) << std::endl;
}