//Kamil Tasarz, 322492

#include <bits/stdc++.h>
#include "wielo.hpp"
using namespace std;

int main()
{
    auto xd = new double[4];
    xd[0] = 1.0;
    xd[1] = 1.5;
    xd[2] = 1.66;
    xd[3] = -13.0;

    wielomian x = wielomian(3, xd);
    wielomian y = wielomian(x);
    wielomian z = wielomian({2.0, 2.2, 0, -2.0});
    cout << "x: " << x << "\n"
         << "y: " << y << "\n"
         << "z: " << z << "\n\n";
    // y -= x;
    // cout << "y: " << y << "\n";

    y = x + x + x;
    cout << "x: " << x << "\n"
         << "y: " << y << "\n"
         << "3x: " << 3 * x << "\n\n";
    x *= 3;
    y -= x * (2.0 / 3);

    cout << "x: " << x << "\n"
         << "y: " << y << "\n"
         << "xy: " << x * y << "\n\n";

    cout << "x(1): " << x(1) << "\n"
         << "y(2.1): " << y(2.1) << "\n\n";

    cout << "x[0]: " << x[0] << "\n"
         << "y[2]: " << y[2] << "\n";

    return 0;
}