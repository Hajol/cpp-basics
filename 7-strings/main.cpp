#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() 
{
	string file_name;

	cout << "Write file name -> ";
	cin >> file_name;
	file_name += ".txt";
	ifstream fin(file_name);

	if (!fin.is_open()) 
	{
		cout << "can't open "<< file_name << endl;
		return 1;
	}

	cout << "Quotes : " << endl;
	string s;
	bool end_quote = false;
	while (getline(fin, s, '"'))
	{
		if (end_quote)
		{
			cout << s << endl;
			end_quote = false;
		}
		else
			end_quote = true;
	}
	fin.close();
	return 0;
}