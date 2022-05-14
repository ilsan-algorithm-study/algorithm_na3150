#include<iostream>
#include <vector>
using namespace std;
vector<int>arr(6);
int N; //식사 횟수
int Max;

void dfs(int level, int sum)
{
	if (level == N)
	{
		if (sum > Max) Max = sum;
		return;
	}
	if (level != 0) //먹이 증식
	{
		for (int x = 0; x < 6; x++)
			arr[x] *= 2;
	}
	vector<int>backup = arr;
	for (int i = 0; i <= 2; i++) { //1번 독수리
		for (int j = 3; j <= 5; j++) { //2번 독수리
			for (int k = 1; k <= 4; k++) { //3번 독수리
				int hap = arr[i];
				arr[i] = 0;
				hap += arr[j];
				arr[j] = 0;
				hap += arr[k];
				arr[k] = 0;
				dfs(level + 1, sum + hap);
				arr = backup;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 6; i++)
		cin >> arr[i];
	cin >> N;
	dfs(0, 0);
	cout << Max;
	return 0;
}