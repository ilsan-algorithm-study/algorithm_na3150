#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<char>>map;
int Max;
string maxStr;
int N;

int direct[5][2] = {
	0,0,
	1,0,
	-1,0,
	0,1,
	0,-1
};

void dfs(int level, int count, string str) {
	if (level == N) {
		if (count > Max) {
			Max = count;
			maxStr = str;
		}
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int cnt = 0;
			char alpha = map[i][j];
			if (alpha == '_') continue;
			vector<vector<char>>backup = map;
			for (int k = 0; k < 5; k++)
			{
				int dx = i + direct[k][0];
				int dy = j + direct[k][1];
				if (dx < 0 || dy < 0 || dx >= 4 || dy >= 4) continue;
				if (map[dx][dy] == '_') continue;
				map[dx][dy] = '_';
				cnt++;
			}
			dfs(level + 1, count + cnt, str + alpha);
			map = backup;
		}
	}
}

int main()
{
	map.assign(4, vector<char>(4, 0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> map[i][j];
	cin >> N;
	dfs(0, 0, "");
	sort(maxStr.begin(), maxStr.end());
	for (int i = 0; i < maxStr.length(); i++)
		cout << maxStr[i] << " ";
	return 0;
}