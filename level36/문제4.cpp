#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int map[5][5];
int n;
int Max;

void rotate(int index)
{
	int backup = map[index][n - 1];
	for (int i = n - 1; i > 0; i--)
		map[index][i] = map[index][i - 1];
	map[index][0] = backup;
}
int getScore()
{
	int score = 1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++)
			sum += map[j][i];
		score *= sum;
	}
	return score;
}

void dfs(int level)
{
	if (level == n) {
		if (Max < getScore()) Max = getScore();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		rotate(level);
		dfs(level + 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	dfs(0);
	cout << Max << "Á¡";
	return 0;
}