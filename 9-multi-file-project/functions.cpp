#include "functions.h"

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
	double sum = 0.0;
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
		sum += arr[i];
	}
	return sum;
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