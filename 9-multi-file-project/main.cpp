#include "functions.h"

using namespace std;

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
	cout << "\n Sum of the elements between the first and second negative: " << GetSum(arr, n) << endl;
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