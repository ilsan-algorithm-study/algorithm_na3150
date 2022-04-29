#include <iostream>
#include <string>
using namespace std;

int n;
int cnt;

void run(int level, int sum)
{
	if (level == n)
	{
		if (sum == 7) cnt++;
		return;
	}
	for (int i = 0; i <= 9; i++)
		run(level + 1, sum + i);
}

int main()
{
	cin >> n;
	run(0, 0);
	cout << cnt;
	return 0;
}