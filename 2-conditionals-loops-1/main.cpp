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
		cout << endl << string(37, '-') << endl;
		cout << "|" << setw(9) << "x" << setw(9);
		cout << "|" << setw(9) << "f" << setw(9) << "|";
		cout << endl << string(37, '-') << endl;

		cout << fixed;
		cout.precision(3);

		while (x1 <= x2)
		{
			if ((c < 0) && (abs(a) > EPS))
			{
				f = -a * pow(x1,2);
			}
			else
			{
				if ((c > 0) && (abs(a) < EPS))
				{
					if (abs(c * x1) > EPS)
						f = (a - x1) / c * x1;
					else
					{
						cout << "|" << setw(11) << x1 << setw(7);
						cout << "|" << "  division by zero  |\n";
						x1 += dx;
						continue;
					}
				}
				else 
					if (abs(c) > EPS)
					f = x1 / c;
				else 
				{ 
					cout << "|" << setw(11) << x1 << setw(7);
					cout << "|" << "  division by zero  |\n";
					x1 += dx;
					continue;
				}
			}

			cout << "|" << setw(11) << x1 << setw(7) << "|";

			if (((int(a)  ^ int(b)) & (int(a) | int(c))) != 0)
				cout << setw(11) << f << setw(7);
			else
				cout << setw(9) << int(f) << setw(9);

			cout << "|" << endl;

			x1 += dx;
		}
		cout << string(37, '-') << endl;
	}
	else
		cout << "Error dx";

	return 0;
}