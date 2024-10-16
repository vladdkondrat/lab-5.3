#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double g(const double x);

int main()
{
    double zp, zk, h;
    int n;

    cout << "zp = "; cin >> zp;
    cout << "zk = "; cin >> zk;
    cout << "n  = "; cin >> n;

    cout << fixed;
    cout << "-----------------------------------------------" << endl;
    cout << "|" << setw(5) << "z" << "     |"
        << setw(20) << "result" << "              |"
        << endl;
    cout << "-----------------------------------------------" << endl;

    double dz = (zk - zp) / n;
    double z = zp;

    while (z <= zk)
    {
        h = g(2 * z) + pow(g(2 * z + z * z), 2) + g(1.5);
        cout << "|" << setw(7) << setprecision(2) << z << "   |"
            << setw(20) << setprecision(5) << h << "              |"
            << endl;
        z += dz;
    }
    cout << "-----------------------------------------------" << endl;
    return 0;
}

double g(const double x)
{
    if (abs(x) >= 1)
        return sin(x) / (cos(x) + 2);
    else
    {
        double S = 1; // Initial term for n=0
        double term = 1; // a0 = 1
        for (int n = 1; n <= 6; n++)
        {
            term *= (x * x) / (2 * n * (2 * n - 1)); 
            S += term;
        }
        return S;
    }
}
