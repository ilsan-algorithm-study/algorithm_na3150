#include <iostream>
#include <string>
#include <vector>
using namespace std;
int cnt;

void run(int x, int y)
{
	if (y == 7) {
		cnt++;
		return;
	}
	for (int i = -1; i <= 1; i++) //3가지 방향
	{
		int dx = x + i;
		if (dx < 0 || dx>2) continue; //배열 범위 벗어나는 경우
		run(dx, y + 1);
	}
}


int main()
{
	char a;
	cin >> a;
	run(a - 'A', 0);
	cout << cnt;
	return 0;
}
