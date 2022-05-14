#include <iostream>
#include <string>
using namespace std;

char arr[3];
char path[3];
int used[3];

void run(int level)
{
	if (level == 3)
	{
		cout << path << endl;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (used[i]) continue;
		used[i] = 1;
		path[level] = arr[i];
		run(level + 1);
		used[i] = 0;
	}
}

int main()
{
	for (int i = 0; i < 3; i++)
		cin >> arr[i];
	run(0);

	return 0;
}
