#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 3) - 3 * pow(x, 2) - 17 * x + 22;
}

double fi(double x) {
    return (pow(x, 3) - 3 * pow(x, 2) + 22) / 17;
}


int main() {
    double eps = 0.0001;

    cout << "You can change epsilon, input it: " << endl;
    while (cin.peek() != '\n')
        cin >> eps;

    int n = 0, n0;
    double x0 = 1.3, xn, delta, q = 0.176, dif = 0.175;

    n0 = int(log(dif / ((1 - q) * eps)) / log(1 / q)) + 1;
    cout << "prior quantity of iterations = " << n0 << endl << endl;

    do {
        xn = fi(x0);
        delta = fabs(xn - x0);
        x0 = xn;
        n++;
        cout << "iteration: " << n << " | " << "x: " << scientific << xn << " | f(x): " << scientific << f(xn) << endl;
    } while (delta >= eps);

    cout << endl << "minimum root xn = " << xn << " | f(xn) = " << f(xn) << endl;
    cout << endl << "number of iteration = " << n;

    return 0;
}