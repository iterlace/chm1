#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 3 * pow(x, 2) - 17 * x + 22;
}

int main() {
    double eps = 0.0001;

    cout << "You can change epsilon, input it: " << endl;
    while (cin.peek() != '\n')
        cin >> eps;

    double xn, x0 = 1.3, t0 = 0.054;
    int n = 0;
    int n0;
    double q = 0.081, z0 = 0.7;
    n0 = int(log(z0 / eps) / log(1 / q)) + 1;
    cout << "prior quantity of iterations = " << n0 << endl << endl;

    do {
        xn = x0 + t0 * f(x0);
        x0 = xn;
        n++;
        cout << "iteration: " << n << " | " << "x: " << scientific << xn << " | f(x): " << scientific << f(xn) << endl;
    } while (abs(f(xn)) > eps);


    cout << endl << "minimum root xn = " << xn << " | f(xn) = " << f(xn) << endl;
    cout << endl << "number of iteration = " << n;

    return 0;
}