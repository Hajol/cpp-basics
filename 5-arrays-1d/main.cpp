#include <iostream>

using namespace std;

void preobr(float *array, int n)
{
	int k = 0;
	double buf;
	for (int i = 0; i < n; i++)
		if (abs(array[i]) <= 1)
		{
			buf = array[k];
			array[k] = array[i];
			array[i] = buf;
			k++;
		}

}

int main()
{
	int i, n;
	float min;
check:
	cout << "Write the number of array elements (n>0), n=";
	cin >> n;
	if (n <= 0)
	{
		cout << "Input error n <=0 " << endl;
		goto check;
	}

	float *array = new float[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter " << i + 1 << " element:";
		cin >> array[i];
	}

	min = array[0];
	for (int i = 0; i < n; i++)
	{
		min = float(i + 1);
	}

	cout << "The minimum element number of the array is : " << min << endl;

	int first, last, sum = 0;
	for (first = 0; first < n; first++)
	{
		if (array[first] < 0) break;
	}
	for (last = n - 1; last > first; last--)
	{
		if (array[last] < 0) break;
	}
	for (i = first + 1; i < last; i++)
	{
		sum += int(array[i]);
	}
	cout << "amount =  : " << sum << endl;
	preobr(array, n);

	for (int i = 0; i < n; i++)
	{

		cout << " [" << i << "] = ";
		cout << array[i] << endl;
	}
	delete[] array;
	return 0;

}