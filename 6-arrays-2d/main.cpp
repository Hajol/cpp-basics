#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define Row 3
#define Col 3

using namespace std;

int SumInColumn(int arr[Row][Col], int column) {
	int result = 0;
	for (int i = 0; i < Row; i++)
	{
		result += arr[i][column];
	}
	return result;
}

void SwapColumns(int arr[Row][Col], int col_1, int col_2) {
	for (int i = 0; i < Row; i++)
	{
		swap(arr[i][col_1], arr[i][col_2]);
	}
}

void GetSubzeroModulo(int arr[Row][Col], int Subzero_Modulo[Col]) {
	for (int i = 0; i < Col; i++)
	{
		Subzero_Modulo[i] = 0;
		for (int j = 0; j < Row; j++)
		{
			if (arr[j][i] < 0)
				Subzero_Modulo[i] += abs(arr[j][i]);
		}
	}
}

void BubbleSort(int arr[Row][Col], int Subzero_Modulo[Col])
{
	for (int i = 0; i < Col - 1; i++)
	{
		for (int j = 0; j < Col - 1 - i; j++)
		{
			if (Subzero_Modulo[j] > Subzero_Modulo[j + 1])
			{
				SwapColumns(arr, j, j + 1);
			}
		}
	}
}

void PrintSumColumns(int arr[Row][Col], int N[Col]) {
	cout << "Sum In Columns with subzero elements: \n";
	bool have = false;
	for (int i = 0; i < Col; i++)
	{
		if (N[i] > 0) {
			cout << i + 1 << ". sum = " << SumInColumn(arr, i) << endl;
			have = true;
		}
	}
	if (!have)
		cout << "No columns with subzero elements!!!\n";
}

void PrintArray(int arr[Row][Col])
{
	cout << "Array: " << endl;
	cout << string(16, '-') << endl;
	for (int i = 0; i < Row; i++)
	{
		cout << "|";
		for (int j = 0; j < Col; j++)
		{
			cout << setw(3) << arr[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << string(16, '-') << endl << endl;
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

	cout << "Sorted array: \n\n";
	int N[Col];
	GetSubzeroModulo(arr, N);
	BubbleSort(arr, N);
	PrintArray(arr);

	PrintSumColumns(arr, N);

	return 0;
}