#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define Row 3
#define Col 3

using namespace std;

void TheSumOfElements(int a[Row][Col],int N[Col])
{
	for (int i = 0; i < Col; i++)
	{
		N[i] = 0;
		for (int j = 0; j < Row; j++)
		{
			if (a[j][i] < 0 )
			{
				N[i] += a[j][i];
			}
		}
	} 
}

void SwapRows(int a[Row][Col], int r1, int r2) 
{
	int N[Col];
	for (int i = 0; i < Col; i++)
	{
		N[i] = a[r1][i];
	}
	for (int i = 0; i < Col; i++)
	{
		a[r1][i] = a[r2][i];
		a[r2][i] = N[i];
	}
}

void SortingArray(int a[Row][Col]) 
{
	int N[Row] = { 0,0,0};
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if ((a[i][j] > 0) && (a[i][j] % 2 != 0))
				N[i] += abs(a[i][j]);
		}
	}

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Row - i - 1; j++)
		{
			if (N[j] > N[j + 1]) {
				swap(N[j], N[j + 1]);
				SwapRows(a, j, j + 1);
			}
		}
	}
}

void PrintArray(int arr[Row][Col]) 
{
	cout << "Array: " << endl;
	cout << string(21, '-') << endl;
	for (int i = 0; i < Row; i++) 
	{
		cout << "|";
		for (int j = 0; j < Col; j++) 
		{
			cout << setw(3) << arr[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(21, '-') << endl << endl;
}

void ReadArray(int arr[Row][Col], string name) 
{
	ifstream fin(name + ".txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
		return;
	}
	for (int i = 0; i < Row; i++) 
	{
		for (int j = 0; j < Col; j++) 
		{
			fin >> arr[i][j];
		}
	}
	fin.close();
}

int main() 
{
	int arr[Row][Col];
	ReadArray(arr, "file");
	PrintArray(arr);
	SortingArray(arr);
	PrintArray(arr);
	cout << "Sum elements: " << endl;
	int N[Col];
	TheSumOfElements(arr, N);

	for (int i = 0; i < Col; i++)
	{
		cout << i+1 << ". " << N[i] << endl;
	}
	cout << endl << endl;
	return 0;
}