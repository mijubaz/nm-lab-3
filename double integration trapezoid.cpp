#include <iostream>
#include <iomanip>
#include <vector>

double f(double x, double y) {
    return x * x + y * y;
}

double doubleTrapezoidal(double ax, double bx, int nx, double ay, double by, int ny) {
    double hx = (bx - ax) / nx;
    double hy = (by - ay) / ny;
    double sum = 0.0;
    for (int i = 0; i <= nx; ++i) {
        double x = ax + i * hx;
        for (int j = 0; j <= ny; ++j) {
            double y = ay + j * hy;
            double weight = 1.0;
            if (i == 0 || i == nx) weight *= 0.5;
            if (j == 0 || j == ny) weight *= 0.5;
            sum += weight * f(x, y);
        }
    }
    return sum * hx * hy;
}

int main() {
    double ax, bx, ay, by;
    int nx, ny;
    std::cin >> ax >> bx >> nx >> ay >> by >> ny;
    double result = doubleTrapezoidal(ax, bx, nx, ay, by, ny);
    std::cout << std::fixed << std::setprecision(10) << result << std::endl;
    return 0;
}
