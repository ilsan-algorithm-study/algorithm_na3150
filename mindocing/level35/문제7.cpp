#include <iostream>
#include <string>
#include <vector>
using namespace std;

int used[5];
int arr[5];
int Min, Max;
int path[5];

int getCalculation()
{
	return path[0] * path[1] - path[2] * path[3] + path[4];
}

void run(int level) {
	if (level == 5)
	{
		int result = getCalculation();
		if (result > Max) Max = result;
		if (result < Min) Min = result;
		return;
	}
	for (int i = 0; i < 5; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		path[level] = arr[i];
		run(level + 1);
		used[i] = 0;
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	run(0);
	cout << Max << "\n" << Min;
	return 0;
}