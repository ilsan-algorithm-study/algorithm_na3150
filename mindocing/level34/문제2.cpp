#include <iostream>
using namespace std;
//�ڵ��� �⸧ ä���
//parametric search 

int main()
{
	string str;
	cin >> str;
	int Max = -1;
	int start = 0, end = 9;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (str[mid] == '#' && mid > Max) Max = mid;
		if (str[mid] == '_') end = mid - 1;
		if (str[mid] == '#') start = mid + 1;
	}
	cout << (Max + 1) * 10 << "%";
	return 0;
}