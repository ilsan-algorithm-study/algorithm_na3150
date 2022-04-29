#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int cnt;
int even; //짝수의 개수
string path = "    ";
int used[6];
string str;
unordered_map<string, int>h;

void run(int level)
{
	if (level == 4)
	{
		if (h.count(path) > 0) return; //이미 구한 숫자이면
		h[path] = 1;
		cnt++;
		if ((int)(path[3] - '0') % 2 == 0) even++; //마지막 자리수만 검사
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if (used[i]) continue;
		used[i] = 1;
		path[level] = str[i];
		run(level + 1);
		used[i] = 0;
	}
}

int main()
{
	cin >> str;
	run(0);
	cout << cnt << " " << even << " " << cnt - even;
	return 0;
}