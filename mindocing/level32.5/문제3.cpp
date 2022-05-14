#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string arr[3] = { "ABCEFG","HIJKLM","NOPQRS" };

string backup[3] = { "ABCEFG","HIJKLM","NOPQRS" };

int direct[5][2] = {
	0,1,
	1,0,
	-1,0,
	0,-1,
	0,0
};

void change(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		int dx = x + direct[i][0];
		int dy = y + direct[i][1];
		if (dx < 0 || dy < 0 || dx > 2 || dy > 5) continue; //범위를 벗어나는 경우
		if (arr[dx][dy] == '#') arr[dx][dy] = backup[dx][dy];
		else arr[dx][dy] = '#';
	}
}

void find(char alpha) //좌표 찾기
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < arr[i].length(); j++)
			if (backup[i][j] == alpha)
				change(i, j);
}

int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		find(str[i]);
	}
	for (int i = 0; i < 3; i++)
		cout << arr[i] << endl;

	return 0;
}