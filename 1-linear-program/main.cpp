#include <iostream>
#include <math.h>
using namespace std;

double z1;
double z2;
double x ;
double y ;
int main()
{

	cout << "Enter x" << endl;
	cin >> x;
	cout << "Enter y" << endl;
	cin >> y;

	z1 = pow(cos(x), 4) + pow(sin(y),2) + (1.0 / 4.0)*pow(sin(2 * x), 2) - 1;
	z2 = sin(y + x) * sin(y - x);

	cout << "\nz1 = " << z1 << "\nz2 = " << z2 << endl;
	return 0;
}