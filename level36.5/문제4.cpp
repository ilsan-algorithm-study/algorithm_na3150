#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int flag;
vector<string>arr(5);
vector<pair<int, int>>middle;

int direct[8][2] = {
	-1,-1,
	-1,0,
	-1,1,
	0,1,
	1,1,
	1,0,
	1,-1,
	0,-1
};

bool findPattern() { //'AAA' ���� ã�� �Լ�
	for (int i = 0; i < n; i++)
	{
		if (arr[i].find("AAA") != -1) return 1;
	}
	return 0;
}

void rotate(int x, int y)
{
	char backup[8];
	for (int i = 0; i < 8; i++) //bacup�迭�� �׵θ� ����
	{
		int dx = x + direct[i][0];
		int dy = y + direct[i][1];
		backup[i] = arr[dx][dy];
	}

	for (int i = 0; i < 6; i++)
	{
		int dx = x + direct[i + 2][0];
		int dy = y + direct[i + 2][1];
		arr[dx][dy] = backup[i];
	}
	arr[x - 1][y - 1] = backup[6];
	arr[x - 1][y] = backup[7];
}

void dfs(int level)
{
	if (findPattern()) {
		flag = 1;
		return;
	}
	if (level >= 6) return;
	for (int i = 0; i < (n - 2) * (n - 2); i++)
	{
		rotate(middle[i].first, middle[i].second);
		dfs(level + 1);
	}
}

int main()
{
	cin >> n; //������ ������
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= n - 2; j++)
			middle.push_back({ i,j });
	dfs(0);
	if (flag) cout << "����";
	else cout << "�Ұ���";
	return 0;
}