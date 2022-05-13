#include <iostream>
#include <string>
#include <vector>
using namespace std;
//��� �������� �����Ͽ� ���� �� �ִ� ������ �ִ� �ݾ�
int Max = -21e8;
int N;

void dfs(int day, int sum, vector<pair<int, int>>schedule)
{
	if (day >= N) {
		if (sum > Max) Max = sum;
		return;
	}
	for (int i = day; i < N; i++)
		dfs(i + schedule[i].first, sum + schedule[i].second, schedule);
}

int main()
{
	cin >> N;
	vector<pair<int, int>>schedule(N); //{�ҿ���, �޴� ����}
	for (int i = 0; i < N; i++)
		cin >> schedule[i].first >> schedule[i].second;
	dfs(0, 0, schedule);
	cout << Max;

	return 0;
}