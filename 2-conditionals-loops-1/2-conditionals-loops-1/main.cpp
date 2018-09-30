#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;


int main() {
	double a, b, c, x1, x2, dx, f;
	const double EPS = 1e-15;
	cout << fixed;
	cout << "Enter a ";
	cin >> a;
	cout << "Enter b ";
	cin >> b;
	cout << "Enter c ";
	cin >> c;
	cout << "Enter x1 ";
	cin >> x1;
	cout << "Enter x2 ";
	cin >> x2;
	cout << "Enter dx ";
	cin >> dx;
	if (dx > EPS)
	{
		cout << string(25, '-') << endl;
		cout << "|     X     |     F     |" << endl;
		cout << string(25, '-') << endl;
		cout.precision(3);
		while (x1 <= x2) {
			if ((c < 0) and (abs(a) > EPS))
			{
				f = -a * pow(x1, 2);
			}
			else if ((c > 0) | (abs(a) < EPS))
			{
				f = (a - x1) / (c * x1);
			}
			else
			{
				f = x1 / c;
			}

			if (abs(int(a) & (int(b) | int(c))) > EPS) {
				cout << "|" << setw(6) << x1 << setw(6) << "|";
				cout << setw(6) << f << setw(6) << "|" << endl;
			}
			else {
				cout << "|" << setw(6) << x1 << setw(6) << "|";
				cout << setw(6) << int(f) << setw(6) << "|" << endl;
			}
			x1 += dx;
		}
		cout << string(25, '-') << endl;
	}
	else
	{
		cout << "Error dx";
	}
	return 0;
}