#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int cnt;
int arr[10];

void dfs(int level, int result)
{
	if (result > 100) return;
	if (result == 100) {
		cnt++;
		return;
	}
	if (level == n - 1) return;
	dfs(level + 1, (result - arr[level + 1]) * (result - arr[level + 1]));
	dfs(level + 1, (result > arr[level + 1]) ? result : arr[level + 1]);
	dfs(level + 1, result * result - arr[level + 1] * arr[level + 1]);
	dfs(level + 1, (result + arr[level + 1]) * (result + arr[level + 1]));
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dfs(0, arr[0]);
	cout << cnt;
	return 0;
}