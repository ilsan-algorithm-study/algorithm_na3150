#include <iostream>
#include <string>
#include <vector>
using namespace std;
//а╤гу
vector<int>arr(9);
vector<int>used(9);
int Max;
int maxCount;

void dfs(int level,int start, int mul)
{
	if (level == 3)
	{
		if (mul == Max) maxCount++;
		if (mul > Max) { 
			Max = mul;
			maxCount = 1;
		}
		return;
	}
	for (int i = start; i < 9; i++)
	{
		if (used[i] == 1) continue;
		used[i] = 1;
		dfs(level + 1,i+1, mul * arr[i]);
		used[i] = 0;
	}
}

int main()
{
	for (int i = 0; i < 9; i++)
		cin >> arr[i];
	dfs(0,0, 1);
	cout << maxCount;
	return 0;
}