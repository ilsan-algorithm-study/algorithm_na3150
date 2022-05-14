#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>>map;

char parent[100]; //DAT ����
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXWZ";

char getBoss(char ch) {

	if (parent[ch] == 0) return ch; //�ڽ��� ������ ���
	int ret = getBoss(parent[ch]); //�θ��� ��带 ã�� �ö�
	parent[ch] = ret;
	return ret;
}

void setUnion(char c1, char c2) { //�׷츸���(�߰�)

	int a = getBoss(c1);
	int b = getBoss(c2);

	//������ �ٸ� ��� = �ٸ� �׷��� ���
	if (a != b)parent[b] = a;
}


int main()
{
	int n;
	cin >> n;
	map.assign(n, vector<int>(n, 0));
	vector<int>checked(n);
	int flag = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j]) { 
				if (checked[j]==0 && getBoss(alpha[i]) == getBoss(alpha[j])) flag = 1;
				setUnion(alpha[i], alpha[j]);
				checked[i] = 1;
			}
		}
	if (flag) cout << "cycle �߰�";
	else cout << "�̹߰�";
	return 0;
}