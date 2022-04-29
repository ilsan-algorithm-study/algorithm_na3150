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
	for (int i = -1; i <= 1; i++) //3���� ����
	{
		int dx = x + i;
		if (dx < 0 || dx>2) continue; //�迭 ���� ����� ���
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