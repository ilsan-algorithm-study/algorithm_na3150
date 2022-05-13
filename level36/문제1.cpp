#include <iostream>
#include <string>
#include <vector>
using namespace std;
//상담 스케쥴을 조정하여 얻을 수 있는 수익의 최대 금액
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
	vector<pair<int, int>>schedule(N); //{소요일, 받는 수익}
	for (int i = 0; i < N; i++)
		cin >> schedule[i].first >> schedule[i].second;
	dfs(0, 0, schedule);
	cout << Max;

	return 0;
}