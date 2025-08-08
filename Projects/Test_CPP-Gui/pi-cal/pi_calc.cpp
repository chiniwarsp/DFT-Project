#include <boost/multiprecision/cpp_dec_float.hpp>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <sstream>

extern "C" {

// Compute pi using Chudnovsky algorithm and Boost.Multiprecision
void compute_pi(char *out, int decimal_digits) {
  using Real = boost::multiprecision::cpp_dec_float_100;

  Real C = 426880 * sqrt(Real(10005));
  Real M = 1;
  Real L = 13591409;
  Real X = 1;
  Real K = 6;
  Real S = L;

  int terms = 10; // increase if needed

  for (int k = 1; k < terms; ++k) {
    M = (M * (K * K * K - 16 * K)) / (Real(k) * Real(k) * Real(k));
    L += 545140134;
    X *= -262537412640768000.0;
    S += (M * L) / X;
    K += 12;
  }

  Real pi = C / S;

  std::ostringstream oss;
  oss << std::fixed << std::setprecision(decimal_digits) << pi;
  std::string result = oss.str();
  std::strncpy(out, result.c_str(), result.size() + 1);
}
}
