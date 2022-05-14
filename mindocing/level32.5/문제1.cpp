#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
	string arr[6] = { "ABCD","ABCE","AGEH","EIEI","FEQE","ABAD" };
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0; i < 6; i++)
	{
		int flag = 0;
		for (int j = 0; j < 4; j++)
		{
			if (str[j] == '?') continue;
			if (str[j] != arr[i][j]) flag = 1;
		}
		if (flag == 0) cnt++;
	}
	cout << cnt;
		return 0;
}