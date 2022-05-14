#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int backup[10];
int compare(int a, int b)
{
	if (backup[a] < backup[b]) return 0;
	if (backup[a] > backup[b]) return 1;
	return a < b; //오름차순
}

int main()
{
	int n;
	cin >> n;
	int a;
	vector<vector<int>>arr(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			arr[i].push_back(a);
		}
	}
	vector<vector<int>>bit(n);
	vector<int>result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a;
			if (a == 1) {
				result.push_back(arr[i][j]);
				backup[arr[i][j]]++;
			}
		}
	}
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}