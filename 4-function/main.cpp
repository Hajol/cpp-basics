#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;
 
void Head() {
	cout << string(60, '-') << "\n|"
		<< setw(8) << "X" << setw(7)
		<< "|" << setw(12) << "arctg(x)"
		<< setw(3) << "|" << setw(12)
		<< "atan(x)" << setw(3) << "|" << setw(12) << "Iterations" << setw(3) << "|\n"
		<< string(60, '-') << endl;
}
void Table(double arc2, double x, int n )
{
		cout << "|" << setw(14) << x
			<< "|" << setw(14) << arc2 << "|" << setw(14) << atan(x)
			<< "|" << setw(13) << n << "|\n";
}


int main() {
	double X1, X2, dX, Eps;
	const int kMaxIter = 1000;
	cout << fixed;
	cout << "X must be greater than 1\n";
	cout << "Please, enter X start: ";
	cin >> X1;
	cout << "Please, enter X end: ";
	cin >> X2;
	cout << "Please, enter dX: ";
	cin >> dX;
	cout << "Please, enter EPS: ";
	cin >> Eps;

	if (dX > 0 && X2 > 1 && X1 > 1) {


		Head();

		double arc1, arc2;

		for (double x = X1; x <= X2; x += dX) {

			arc1 = 0, arc2 = M_PI_2;

			for (int n = 0; n < kMaxIter; n++) {

				arc2 += pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));

				if (abs(arc2 - arc1) < Eps) 
				{
					Table(arc2, x, n);
					break;
				}


				if (kMaxIter - n < 2) {
					cout << "small EPS";
					return 2;
				}

				arc1 = arc2;
			}
		}
		cout << string(60, '-');
	}

	else {
		cout << "Error , Invalid values";
	}

	return 0;
}