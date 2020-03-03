#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	char s[100];
	cout << "Enter the name of the file:" << endl;
	cin >> s;
	ifstream fin(s, ios::in | ios::nocreate);
	if (!fin)
	{
		cout << "File could not be opened." << endl;
		return 1;
	}
	int n = 1;
	while (!fin.eof())
	{
		fin.getline(s, 100);
		cout << n << ": " << s << endl;
		n++;
	}
	return 0;
}
