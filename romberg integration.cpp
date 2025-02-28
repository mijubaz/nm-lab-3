#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

double f(double x) {
  return x * x;
}

double romberg(double a, double b, int n) {
  std::vector<std::vector<double>> R(n + 1, std::vector<double>(n + 1, 0.0));
  R[0][0] = 0.5 * (b - a) * (f(a) + f(b));
  double h = b - a;
  for (int i = 1; i <= n; ++i) {
    h /= 2.0;
    double sum = 0.0;
    for (int k = 1; k <= pow(2, i - 1); ++k) {
      sum += f(a + (2.0 * k - 1.0) * h);
    }
    R[i][0] = 0.5 * R[i - 1][0] + h * sum;
    for (int j = 1; j <= i; ++j) {
      R[i][j] = R[i][j - 1] + (R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
    }
  }
  return R[n][n];
}

int main() {
  double a, b;
  int n;
  std::cin >> a >> b >> n;
  double result = romberg(a, b, n);
  std::cout << std::fixed << std::setprecision(10) << result << std::endl;
  return 0;
}
