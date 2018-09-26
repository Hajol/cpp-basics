# include <iostream>
# include <iomanip> 
# include <cstdlib> 
# include <math.h> 
# include <ctime> 
using namespace std;

double z1 = 0;
double z2 = 0;
int a = 0;
const double PI = 3.14159265;
int main()
{
	setlocale(LC_CTYPE, "Russian");

	cout << "Enter a" << endl;
	cin >> a;

	z1 = pow(cos(3.0 / 8.0*PI - a / 4.0), 2) - pow(cos(11.0 / 8.0 * PI + a / 4.0), 2);
	z2 = sqrt(2) / 2 * sin(a / 2);

	cout << "if a = " << a << " z1 = " << z1 << "then  z2 = " << z2 << endl;
	return 0;
}