#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
int Max;
string maxNums;
vector<int>arr;

void dfs(int count,int sum, string nums)
{
	if (count == N) {
		if (sum > Max) {
			Max = sum;
			maxNums = nums;
		}
		return;
	}
	if (count >= N) return;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 0) continue; //타버린 경우
		int score = arr[i], cnt = 0; //점수, 불태운 개수
		vector<int>backup = arr; //백업
		for (int j = i - 1; j <= i + 1; j++)
		{
			if (j >= 0 && j < N && arr[j] > 0) {
				arr[j] = 0;
				cnt++;
			}
		}
		dfs(count+cnt, sum + score, nums + "+"+ to_string(score));
		arr = backup;
	}
}

int main()
{
	cin >> N;
	arr.assign(N, 0);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	dfs(0,0, "");
	for (int i = 1; i < maxNums.length(); i++)
		cout << maxNums[i];
	cout << "=" << Max;
	return 0;
}