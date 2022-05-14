#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<vector<int>>map;

char parent[100]; //DAT 저장
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXWZ";

char getBoss(char ch) {

	if (parent[ch] == 0) return ch; //자신이 보스인 경우
	int ret = getBoss(parent[ch]); //부모의 노드를 찾아 올라감
	parent[ch] = ret;
	return ret;
}

void setUnion(char c1, char c2) { //그룹만들기(추가)

	int a = getBoss(c1);
	int b = getBoss(c2);

	//보스가 다른 경우 = 다른 그룹인 경우
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
	if (flag) cout << "cycle 발견";
	else cout << "미발견";
	return 0;
}