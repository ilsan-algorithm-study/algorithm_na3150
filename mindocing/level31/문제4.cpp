#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string str[5];
	for (int i = 0; i < 5; i++)
		cin >> str[i];
	for (int i = 0; i < 5; i++)
	{
		swap(str[i][1], str[i][3]);
		if (str[i] == "MAPOM") { 
			cout << "yes";
			return 0;
		}
	}
	cout << "no";
	return 0;
}