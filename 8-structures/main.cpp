#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TRAIN
{
	string destination;
	string number;
	string time;
};

bool IsTime(string s) {
	if (isdigit(s[0]) &&
		isdigit(s[1]) &&
		isdigit(s[3]) &&
		isdigit(s[4]) &&
		s[2] == ':' &&
		((s[0] < '6') &&
		(s[3] < '6'))) {
		return true;
	}
	else {
		return false;
	}
}

void AddTrain(TRAIN t[], int const size) {
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". Train\n";
		cout << "Enter destination -> ";
		getline(cin, t[i].destination);
		cout << "Enter number of the train -> ";
		getline(cin, t[i].number);
		while (true) {
			cout << "Enter start time (hh:mm) -> ";
			getline(cin, t[i].time);
			if (IsTime(t[i].time))
				break;
			else
				cout << "Indalid time format!\n";
		}
		cout << endl;
	}
}

void SortTrain(TRAIN t[], int const size) {
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (t[j].time.compare(t[j + 1].time) > 0)
				swap(t[j], t[j + 1]);
		}
	}
}

void PrintTrain(TRAIN t[], int const size) {
	cout << string(44, '-') << endl;
	cout << "|" << setw(20) << "destination";
	cout << "|" << setw(10) << "number";
	cout << "|" << setw(10) << "time";
	cout << "|\n";
	cout << string(44, '-') << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "|" << setw(20) << t[i].destination;
		cout << "|" << setw(10) << t[i].number;
		cout << "|" << setw(10) << t[i].time;
		cout << "|\n";
	}
	cout << string(44, '-') << endl;
}

void FindTrains(TRAIN t[], int const size, string find) {
	bool finded = false;
	for (int i = 0; i < size; i++)
	{
		if (t[i].destination == find) {
			finded = true;
			cout << "|" << setw(20) << t[i].destination;
			cout << "|" << setw(10) << t[i].number;
			cout << "|" << setw(10) << t[i].time;
			cout << "|\n";
		}
	}
	if (!finded)
		cout << "NOT FOUND this destination!\n\n";
}

int main()
{
	int const kSize = 3;
	TRAIN t[kSize];

	//add
	AddTrain(t, kSize);
	PrintTrain(t, kSize);

	//sort
	cout << "\nSorted trans for time:\n";
	SortTrain(t, kSize);
	PrintTrain(t, kSize);
	cout << "\n\n";

	//find
	string find;
	cout << "Enter the destination for search -> ";
	cin >> find;
	FindTrains(t, kSize, find);

	return 0;
}