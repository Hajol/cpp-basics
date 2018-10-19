#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void PrintTableHead() {
	cout << string(60, '-') << endl;
	cout << "|" << setw(8) << "x" << setw(7) << "|";
	cout << setw(12) << "arctg(x)" << setw(4) << "|";
	cout << setw(11) << "atan(x)" << setw(4) << "|";
	cout << setw(11) << "iterations" << setw(3) << "|\n";
	cout << string(60, '-') << endl;
}

double ComputeSeries(double x, double eps, int &n, const int kMaxIters) {
	double arc1, arc2 = M_PI_2;
	for (n = 0; n < kMaxIters; n++) {
		arc1 = pow(-1, n + 1) / ((2 * n + 1) * pow(x, 2 * n + 1));
		arc2 += arc1;
		if (abs(arc1) < eps) break;
	}
	return arc2;
}

void PrintTableRow(double x, double func, int n, const int kMaxIters) {
	cout << "|" << setw(12) << x << setw(3) << "|" << setw(12);
	if (n < kMaxIters)
		cout << func << setw(4) << "|";
	else
		cout << "   max iters   |";
	cout << setw(11) << atan(x) << setw(4) << "|";
	cout << setw(7) << n << setw(7) << "|\n";
}

int main() {
	const int kMaxIters = 1000;

	double xn, xk, dx, eps;
	cout << "Please, enter xn (xn > 1): ";
	cin >> xn;
	cout << "Please, enter xk (xk >= xn): ";
	cin >> xk;
	cout << "Please, enter dx (dx > 0): ";
	cin >> dx;
	cout << "Please, enter eps (eps > 0): ";
	cin >> eps;

	if (dx <= 0) {
		cout << "\nInvalid dx. Must be: dx > 0.\n";
	}
	else if (eps <= 0) {
		cout << "\nInvalid eps. Must be: eps > 0.\n";
	}
	else if (xn <= 1) {
		cout << "\nInvalid xn. Must be: xn > 1.\n";
	}
	else if (xn > xk) {
		cout << "\nInvalid xk. Must be: xk >= xn.\n";
	}
	else {
		PrintTableHead();

		cout << fixed;
		cout.precision(6);

		for (double x = xn; x <= xk; x += dx) {
			int n;
			double arctg = ComputeSeries(x, eps, n, kMaxIters);
			PrintTableRow(x, arctg, n, kMaxIters);
		}
		cout << string(60, '-');
	}

	return 0;
}