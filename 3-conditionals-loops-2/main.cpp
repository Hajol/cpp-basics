#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	double x1, EPS, dx, x2;
	double arc1 = 0, arc2 = M_PI_2;
	const int Max_Iter = 100;

	cout << fixed;
	cout << "x must be greater than 1\n";
	cout << "Enter X start: ";
	cin >> x1;
	cout << "Enter x end: ";
	cin >> x2;
	cout << "Enter dx: ";
	cin >> dx;
	cout << "Enter Eps: ";
	cin >> EPS;

	if (dx > 0 && x2 > 1 && x1 > 1) {


		cout << string(60, '-') << "\n|"
			<< setw(8) << "X" << setw(7)
			<< "|" << setw(12) << "arctg(x)"
			<< setw(3) << "|" << setw(12)
			<< "atan(x)" << setw(3) << "|" << setw(12) << "iterations" << setw(3) << "|\n"
			<< string(60, '-') << endl;


		for (double x = x1; x <= x2; x += dx) {

			for (int n = 0; n < Max_Iter; n++) {

				arc2 +=pow (-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));

				if (abs(arc2 - arc1) < EPS) {
					cout << "|" << setw(14) << x
						<< "|" << setw(14) << arc2 << "|" << setw(14) << atan(x)
						<< "|" << setw(13) << n << "|\n";
					break;
				}


				if (Max_Iter - n < 2) {
					cout << "small EPS";
					return 2;
				}
				arc1 = arc2;
			}
		}
		cout << string(60, '-');
	}

	else {
		cout << "Error , invalid values";
	}
}