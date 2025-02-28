#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
  return x * x;
}

double simpsons38(double a, double b, int n) {
  if (n % 3 != 0) {
    return NAN;
  }
  double h = (b - a) / n;
  double sum = f(a) + f(b);
  for (int i = 1; i < n; i++) {
    if (i % 3 == 0) {
      sum += 2 * f(a + i * h);
    } else {
      sum += 3 * f(a + i * h);
    }
  }
  return (3.0 * h / 8.0) * sum;
}

int main() {
  double a, b;
  int n;
  std::cin >> a >> b >> n;
  if (n <= 0 || b <= a) {
    return 1;
  }
  double result = simpsons38(a, b, n);
  if (!std::isnan(result)) {
    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
  }
  return 0;
}
