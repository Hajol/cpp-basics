#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void head() {
	cout << string(60, '-') << "\n|"
		<< setw(8) << "X" << setw(7)
		<< "|" << setw(12) << "arctg(x)"
		<< setw(3) << "|" << setw(12)
		<< "atan(x)" << setw(3) << "|" << setw(12)
		<< "Iterations" << setw(3) << "|\n"
		<< string(60, '-') << endl;
}

double element(double x, int n) 
{

	double heard = pow(-1, n + 1) / ((2 * n + 1)*pow(x, 2 * n + 1));
	return heard;
}

double arctg(double x, double Eps, int &n) {
	long kMaxIter = 1000;

	double arc1 = 0, arc2 = M_PI_2;

	for (n = 0; n < kMaxIter; n++) {
		arc2 +=element(x, n);

		if (abs(arc2 - arc1) < Eps) {
			break;
		}


		if (kMaxIter - n < 2) {
			break;
		}

		arc1 = arc2;
	}
	return arc2;
}


int bow(double x, double Eps) {
	int n = 0;
	if (arctg(x, Eps, n) == 0) {
		cout << "small EPS";
		return 0;

	}
	else {
		cout << "|" << setw(14) << x
			<< "|" << setw(14) << arctg(x, Eps, n)
			<< "|" << setw(14) << atan(x)
			<< "|" << setw(13) << n << "|\n";
		return 1;
	}
}


int main() {

	double x1, x2, dx, Eps;


	cout << fixed;
	cout << "X must be less than 1\n";
	cout << "Please, enter X start: ";
	cin >> x1;
	cout << "Please, enter X end: ";
	cin >> x2;
	cout << "Please, enter dX: ";
	cin >> dx;
	cout << "Please, enter Eps: ";
	cin >> Eps;


	if (dx > 0 && x2 > 1) {

		head();
		for (double x = x1; x <= x2; x += dx) {

			if (bow(x, Eps)) 
			{
				continue;
			}
			else 
			{
				break;
			}

		}
		cout << string(60, '-');

	}

	else {
		cout <<"Error, Invalid values";
	}

	return 0;
}