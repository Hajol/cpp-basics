#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

double FindArgMin(double *arr, int n);
double GetSum(double *arr, int n);
void TransformArray(double *arr, int n);

int main() 
{
	int n = 0;

	cout << "Enter the number of items (n>0), n=";
	cin >> n;

	double *arr = new double[n];

	for (int i = 0; i < n; i++) 
	{
		cout << "Enter " << i + 1 << " element:";
		cin >> arr[i];
	}
	cout << "\n The minimum element index of the array is : " << FindArgMin(arr, n) << endl;
	cout << "\n Summ of the elements between the first and second negative: " <<GetSum(arr, n) << endl;
	cout << "\n Converted array:" << endl;
	TransformArray(arr, n);
	for (int i = 0; i < n; i++) 
	{

		cout << " [" << i << "] = ";
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}

double FindArgMin(double *arr, int n)
{
	double min = arr[0];
	int min_id = 0;
	for (int i = 1; i < n; i++) 
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_id = i + 1;
		}
	}
	return min_id;
}

double GetSum(double *arr, int n)
{
	double summ = 0.0;
	bool flag = false;
	int begin = 0;
	int end = 0;

	for (int i = 0; i < n; i++) 
	{
		if (arr[i] < 0 && !flag) 
		{
			begin = i;
			flag = true;
		}
		else if (arr[i] < 0 && flag) 
		{
			end = i;
			break;
		}
	}

	for (int i = begin + 1; i < end; i++) 
	{
		summ += arr[i];
	}
	return summ;
}

void TransformArray(double *arr, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - i - 1; j++) 
		{
			if ((abs(arr[j]) > 1) and !(abs(arr[j + 1]) > 1)) 
			{
				swap(arr[j], arr[j + 1]);
			}
		}
}