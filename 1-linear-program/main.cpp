#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	double x , y ;
	double z1, z2;
	cout << "Enter x ";
	cin >> x;
	cout << "Enter y ";
	cin >> y; 
	z1 = pow(cos(x), 4) + pow(sin(y), 2) + (1.0 / 4.0)*pow(sin(2.0 * x),2)-1;
	z2 = sin(y + x) * sin(y - x);
	cout << "z1= " << z1 << endl << "z2= " << z2 << endl;
	return 0;
}