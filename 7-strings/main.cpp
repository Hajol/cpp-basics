#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	string s, file_name;

	cout << "Write  file name (default name 'Text') -> ";
	cin >> file_name;
	file_name += ".txt";
	ifstream fin(file_name);

	if (!fin.is_open()) 
	{
		cout << "can't open file!" << endl;
		return 1;
	}

	cout << "Quote : " << endl;

	int cou = 0;
	while (getline(fin, s, '"'))
	{
		if (cou % 2) std::cout << s << endl;
		++cou;
	}
	fin.close();
	return 0;
}