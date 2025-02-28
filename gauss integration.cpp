#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
  return x * x;
}

double gaussQuadrature(double a, double b, int n) {
  double nodes[] = {
      -0.9324695142, -0.6612093865, -0.2386191861,
      0.2386191861, 0.6612093865, 0.9324695142};
  double weights[] = {
      0.1713244924, 0.3607615730, 0.4679139346,
      0.4679139346, 0.3607615730, 0.1713244924};
  if (n != 6) {
    return NAN;
  }
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    double x = 0.5 * (b - a) * nodes[i] + 0.5 * (a + b);
    sum += weights[i] * f(x);
  }
  return 0.5 * (b - a) * sum;
}

int main() {
  double a, b;
  int n;
  std::cin >> a >> b >> n;
  if (n != 6) {
    return 1;
  }
  double result = gaussQuadrature(a, b, n);
  std::cout << std::fixed << std::setprecision(10) << result << std::endl;
  return 0;
}
