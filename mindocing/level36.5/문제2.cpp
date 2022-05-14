#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
//중복조합
string str;
unordered_map<string, int>used;

void dfs(int level, int start, string result)
{
	if (level == 3)
	{
		if (used.count(result)) return;
		cout << result << endl;
		used[result] = 1;
		return;
	}
	for (int i = start; i < str.length(); i++)
	{
		dfs(level + 1, i, result + str[i]);
	}
}

int main()
{
	cin >> str;
	sort(str.begin(), str.end());
	dfs(0, 0, "");
	return 0;
}