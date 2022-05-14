#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int flag;
vector<vector<int>>map;
vector<vector<int>>visited;

int direct[4][2] = {
	0,1,
	0,-1,
	1,0,
	-1,0
};

void dfs(int x, int y)
{
	if (x == n - 1 && y == n - 1) {
		flag = 1;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int dx = x+ direct[i][0];
		int dy = y+ direct[i][1];
		//배열의 범위를 벗어나는 경우
		if (dx < 0 || dy < 0 || dx >= n || dy >= n) continue;
		//벽이 있는 경우
		if (map[dx][dy] == 1) continue;
		//이미 지나간 곳인 경우
		if (visited[dx][dy] == 1) continue;
		visited[dx][dy] = 1;
		dfs(dx, dy);
		visited[dx][dy] = 0;
	}
}

int main()
{
	cin >> n;
	map.assign(n, vector<int>(n, 0));
	visited.assign(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	dfs(0, 0);
	if (flag) cout << "가능";
	else cout << "불가능";
	return 0;
}