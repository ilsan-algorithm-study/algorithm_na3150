#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>>map;
int N, K;

void rotate() //오른쪽으로 회전
{
	vector<vector<int>>backup = map;
	for (int i = N-1; i >= 0; i--)
	{
		for (int j = 0; j < N; j++)
			map[j][N-i-1] = backup[i][j];
	}
}

int main()
{
	cin >> N >> K;
	map.assign(N, vector<int>(N, 0));
	for (int i =0;i<N;i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	for (int i = 0; i < K; i++)
		rotate();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << map[i][j] << " ";
		cout << endl;
	}
	return 0;
}