#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//디자이너의 손길
//level :3
int n;
string str;
int Max;

int getScore(string str) //예술 점수 계산
{
	int score = 0;
	for (int i = 0; i < str.length() - 1; i++)
	{
		int differ = abs(str[i] - str[i + 1]);
		if (differ == 0) score -= 50;
		else if (differ <= 5) score += 3;
		else if (differ >= 20) score += 10;
	}
	return score;
}

void dfs(int level, int start)
{
	if (level == n) {
		if (getScore(str) > Max) Max = getScore(str);
		return;
	}

	for (int i = start; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] == str[j]) continue;
			swap(str[i], str[j]);
			dfs(level + 1, i + 1);
			swap(str[i], str[j]);
		}
	}
}

int main()
{
	cin >> str;
	cin >> n; //swap 가능한 횟수
	dfs(0, 0);
	cout << Max;
	return 0;
}