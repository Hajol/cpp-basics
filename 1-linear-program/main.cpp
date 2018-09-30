#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

void alert(double x) {
	cout << "|" << setw(10) << x << "|" << setw(10) << "/ 0" << "|" << endl;
}

int main() {
	double a, b, c, x1, x2, dx, f = 0;
	const long double EXP = 0.000000000001;
	cout << "Write a, b, c ";
	cin >> a >> b >> c;
	cout << "Write x(beg), x(end), dx ";
	cin >> x1 >> x2 >> dx;
	cout << fixed;
	cout << string(25, '-') << endl << setw(10) << "X" << setw(10) << "F" << endl << string(25, '-') << endl;

	for (double x = x1; x < x2; x += dx) {
		if ((a < 0) & (abs(x) > EXP))
			f = a * pow(x, 2) + pow(b, 2) * x;
		else
			if ((a > 0) & (abs(x) < EXP))
				if ((x - c) != 0)
					f = x - (a / (x - c));
				else {
					alert(x);
					continue;
				}
			else
				if (c != 0)
					f = 1 + (x / c);
				else {
					alert(x);
					continue;
				}

		if (!((((int)a) | ((int)b)) & (((int)b) | ((int)c))))
			cout << "|" << setw(10) << x << "|" << setw(10) << f << "|" << endl;
		else
			cout << "| " << setw(10) << x << "|" << setw(10) << (int)f << "|" << endl;
	}

	return 0;
}