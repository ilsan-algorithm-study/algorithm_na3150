#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//조합

int price[5] = { 500,700,600,300,400 };
int point[5] = { 30,10,30,40,20 };
int used[5];
int Max;
int limit, T; //한도, 음료 종류

int getPoint()
{
	int Point = 0, Price = 0, count = 0;
	for (int i = 0; i < 5; i++)
		if (used[i]) {
			Price += price[i];
			Point += point[i];
		}
	while (count * Price < limit) count++;
	return (count - 1) * Point;
}

void dfs(int level)
{
	if (level == T) {
		if (Max < getPoint()) Max = getPoint();
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		dfs(level + 1);
		used[i] = 0;
	}
}

int main()
{
	cin >> limit >> T;
	dfs(0);
	cout << Max;
	return 0;
}