#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstring>

#define Row 3
#define Col 3

using namespace std;

template <class T>
T SumInColumn(T arr[Row][Col], int column) {
	T result = 0;
	for (int i = 0; i < Row; i++)
	{
		result += arr[i][column];
	}
	return result;
}

template <class T>
void SwapColumns(T arr[Row][Col], int col_1, int col_2) {
	for (int i = 0; i < Row; i++)
	{
		swap(arr[i][col_1], arr[i][col_2]);
	}
}

template <class T>
void GetSubzeroModulo(T arr[Row][Col], T Subzero_Modulo[Col]) {
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

template <class T>
void BubbleSort(T arr[Row][Col], T Subzero_Modulo[Col])
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

template <class T>
void PrintSumColumns(T arr[Row][Col], T N[Col]) {
	cout << "Sum In Columns with subzero elements: \n";
	bool have = false;
	for (int i = 0; i < Col; i++)
	{
		if (N[i] > 0) {
			cout << i + 1 << ". sum = " << SumInColumn<T>(arr, i) << endl;
			have = true;
		}
	}
	if (!have)
		cout << "No columns with subzero elements!!!\n";
}

template <class T>
void PrintArray(T arr[Row][Col])
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

template <class T>
void ReadArray(T arr[Row][Col], string name)
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

template <class TypeAr>
void start(string name) {
	TypeAr arr[Row][Col];
	ReadArray(arr, name);
	PrintArray(arr);

	cout << "Sorted array: \n\n";
	TypeAr N[Col];
	GetSubzeroModulo(arr, N);
	BubbleSort(arr, N);
	PrintArray(arr);

	PrintSumColumns(arr, N);
}

int main() {
error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") {
		start<int>("int");
	}
	else if (select == "1") {
		start<double>("double");
	}
	else if (select == "2") {
		start<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}