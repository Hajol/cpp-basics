#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void PrintTableHead() {
	cout << string(60, '-') << "\n|"
		<< setw(8) << "X" << setw(7)
		<< "|" << setw(12) << "arctg(x)"
		<< setw(3) << "|" << setw(12)
		<< "atan(x)" << setw(3) << "|" << setw(12)
		<< "Iterations" << setw(3) << "|\n"
		<< string(60, '-') << endl;
}

double arctg(double x, double eps, int &n, const int kMaxIters) {
	double arc1, arc2 = M_PI_2;
	for (n = 0; n < kMaxIters; n++) {
		arc1 = pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));
		arc2 += arc1;

		if (abs(arc1) < eps)
			break;
	}
	return arc2;
}

void CreateRow(double x, double Eps) {
	int n = 0;
	const int kMaxIters = 100;
	double y = arctg(x, Eps, n, kMaxIters);

	cout << "|" << setw(14) << x << "|" << setw(14);
	if (n == kMaxIters)
		cout << "ERROR";
	else
		cout << y;
	cout << "|" << setw(14) << atan(x)
		<< "|" << setw(13) << n << "|\n";
}

int main() {
	double x1, x2, dx, Eps;

	cout << fixed;
	cout << "X must be greater than 1\n";
	cout << "Please, enter X star): ";
	cin >> x1;
	cout << "Please, enter X end: ";
	cin >> x2;
	cout << "Please, enter dX: ";
	cin >> dx;
	cout << "Please, enter eps: ";
	cin >> Eps;

	if (dx > 0 && x2 > 1 && x1 > 1) {
		PrintTableHead();
		for (double x = x1; x <= x2; x += dx)
			CreateRow(x, Eps);
		cout << string(60, '-');
	}
	else
		cout << "Error, Invalid values";

	return 0;
}