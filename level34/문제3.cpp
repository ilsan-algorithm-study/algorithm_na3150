#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string>books;

string BS(string target, int time)
{
	int cnt = 0;
	int start = 0, end = books.size()-1;
	int flag = 0;
	while (cnt < time)
	{
		cnt++;
		int mid = (start + end) / 2;
		if (start > end) break;
		if (books[mid] == target) { 
			flag = 1;
			break;
		}
		if (books[mid] < target) start = mid + 1;
		if (books[mid] > target) end = mid - 1;
	}
	if (flag) return "pass";
	return "fail";
}

int main()
{
	int N;
	cin >> N;
	books.assign(N,"");
	for (int i = 0; i < N; i++)
		cin >> books[i];
	sort(books.begin(), books.end());
	int time;
	cin >> time;
	string title;
	int chance;
	for (int i = 0; i < time; i++)
	{
		cin >> title >> chance;
		cout << BS(title, chance) << endl;
	}
	return 0;
}