#include <iostream>
#include <string>
#include <vector>
using namespace std;

string arr[5] = { "BTS","SBS","BS","CBS","SES" };
string str;
int Min = 21e8;
void run(int count, string s)
{
	if (s.length() > str.length()) return; //backtracking
	if (str == s) {
		if (Min > count) Min = count;
	}
	for (int i = 0; i < 5; i++)
		run(count + 1, s + arr[i]);
}

int main()
{
	cin >> str;
	run(0, "");
	cout << Min;
	return 0;
}
