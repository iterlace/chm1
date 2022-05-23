#include <iostream>
#include <cmath>

using namespace std;


double f(double x) {
    return pow(x, 3) - 3 * pow(x, 2) - 17 * x + 22;
}


int main() {
    double a, b, x, eps = 0.0001;
    a = 1;
    b = 2;
    int n0, n = 0;
    n0 = int(log2((b - a) / eps)) + 1;
    cout << "prior quantity of iterations = " << n0 << endl << endl;

    do {
        x = (a + b) / 2.0;
        n++;
        cout << "iteration: " << n << " | " << "x: " << scientific << x << " | f(x): " << scientific << f(x) << endl;
        if (f(a) * f(x) < 0)
            b = x;
        else if (f(b) * f(x) < 0)
            a = x;
    } while (fabs(b - a) > eps);
    cout << endl << "minimum root xn = " << x << " | f(xn) = " << f(x) << endl;
    cout << endl << "number of iteration = " << n;
    // cout << (a + b) / 2 << endl;

    return 0;
}