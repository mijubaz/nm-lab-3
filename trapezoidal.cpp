#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return x * x;
}

double trapezoidalRule(double a, double b, int n) {
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

    std::cout << "Enter the number of trapezoids (n): ";
    std::cin >> n;

    if (n <= 0 || b <= a) {
        std::cerr << "Invalid input. n must be positive, and b must be greater than a." << std::endl;
        return 1;
    }

    double result = trapezoidalRule(a, b, n);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Approximate integral: " << result << std::endl;

    return 0;
}
