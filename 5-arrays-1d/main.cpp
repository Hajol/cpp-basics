#include <iostream>
#include <cstdlib>
#include <cmath>
#include <locale> 

using namespace std;

double min(double *arr, int n);
double summ(double *arr, int n);
void preobr(double *arr, int n);
int main() {
	int n = 0;


	cout << "Enter the number of items (n>0), n=";
	cin >> n;

	double *arr = new double[n];

	for (int i = 0; i < n; i++) 
	{
		cout << "Enter " << i + 1 << " element:";
		cin >> arr[i];
	}
	cout << "\n The minimum element number of the array is : " << min(arr, n) << endl;
	cout << "\n Sum of elements: " << summ(arr, n) << endl;
	cout << "\n Converted array:" << endl;
	preobr(arr, n);
	for (int i = 0; i < n; i++) {

		cout << " [" << i << "] = ";
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}

double min(double *arr, int n)
{
	double min = arr[0];
	int min_id;
	for (int i = 1; i < n; i++) {
		if (arr[i] < min)
		{
			min = arr[i];
			min_id = i + 1;
		}
	}
	return min_id;
}

double summ(double *arr, int n)
{
	double summ = 0.0;
	bool flag = false;
	int begin = 0;
	int end = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0 && !flag) {
			begin = i;
			flag = true;
		}
		else if (arr[i] < 0 && flag) {
			end = i;
			break;
		}
	}

	for (int i = begin + 1; i < end; i++) {
		summ += arr[i];
	}
	return summ;
}


void preobr(double *arr, int n)
{
	int k = 0;
	double buf;
	for (int i = 0; i < n; i++)
		if (abs(arr[i]) <= 1)
		{
			buf = arr[k];
			arr[k] = arr[i];
			arr[i] = buf;
			k++;

		}

}