#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string str;

int check()
{
	for (int i = 0; i < str.length(); i++)
		if (str[i] != '_') return 0;
	return 1;
}
int main()
{
	cin >> str;
	int len = str.length();
	cout << str << endl;
	while (!check())
	{

		for (int i = 0; i < len; i++)
			if (str[i] != '_') {
				str[i] -= 1;
				if (str[i] < 'A') str[i] = '_';
			}
		cout << str << endl;
	}
	return 0;
}