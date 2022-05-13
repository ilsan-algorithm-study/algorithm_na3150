#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str;
int Min = 21e8;

bool isOk()
{
	for (int i = 0; i < str.length() - 1; i++)
		if (str[i] != str[i + 1]) return 0;
	return 1;
}

void shift(int index) //고기 뒤집기
{
	for (int j = -1; j <= 1; j++)
	{
		int dx = index + j;
		if (dx < 0 || dx > str.length() - 1) continue;
		str[dx] = (str[dx] == 'O')? 'X':'O';
	}
}

void dfs(int level)
{
	int t = 1;
	if (isOK()) {
		if (level < Min) Min = level;
	}
	if (level == 4)  return;
	for (int i = 0; i < str.length(); i++)
	{
		shift(i);
		dfs(level + 1);
		shift(i);
	}
}

int main()
{
	cin >> str;
	dfs(0);
	if (Min <= 4) cout << Min;
	else cout << "impossible";
	return 0;
}