#include <iostream>
#include <cmath>
#include <iomanip>

double f(double x) {
    return x * x;
}

double simpsonsRule(double a, double b, int n) {
    if (n % 2 != 0) {
        std::cerr << "Error: n must be an even number for Simpson's 1/3 rule." << std::endl;
        return NAN; 
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        if (i % 2 == 0) {
            sum += 2 * f(a + i * h); 
        } else {
            sum += 4 * f(a + i * h); 
        }
    }

    return (h / 3.0) * sum;
}

int main() {
    double a, b;
    int n;

    std::cout << "Enter the lower limit of integration (a): ";
    std::cin >> a;

    std::cout << "Enter the upper limit of integration (b): ";
    std::cin >> b;

    std::cout << "Enter the number of intervals (n) (must be even): ";
    std::cin >> n;

    if (n <= 0 || b <= a) {
        std::cerr << "Invalid input. n must be positive, and b must be greater than a." << std::endl;
        return 1;
    }

    double result = simpsonsRule(a, b, n);

    if (!std::isnan(result)) { 
        std::cout << std::fixed << std::setprecision(10);
        std::cout << "Approximate integral: " << result << std::endl;
    }

    return 0;
}
