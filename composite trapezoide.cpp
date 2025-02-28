#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return x * x; 
}

double compositeTrapezoidal(double a, double b, int n) {
    if (n <= 0) {
        std::cerr << "Error: Number of intervals (n) must be positive." << std::endl;
        return NAN; 
    }

    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }

    return sum * h;
}

int main() {
    double a, b;
    int n;

    std::cout << "Enter the lower limit of integration (a): ";
    std::cin >> a;

    std::cout << "Enter the upper limit of integration (b): ";
    std::cin >> b;

    std::cout << "Enter the number of intervals (n): ";
    std::cin >> n;

    if (b <= a) {
        std::cerr << "Error: Upper limit (b) must be greater than lower limit (a)." << std::endl;
        return 1;
    }

    double result = compositeTrapezoidal(a, b, n);

    if (!std::isnan(result)) {
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Approximate integral: " << result << std::endl;
    }

    return 0;
}
