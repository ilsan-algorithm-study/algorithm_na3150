#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	return a < b;
}

int main()
{
	int n;
	cin >> n;
	vector<string>vect(n);
	for (int i = 0; i < n; i++)
		cin >> vect[i];
	sort(vect.begin(), vect.end(), compare);
	for (int i = 0; i < n; i++)
		cout << vect[i] << endl;
	return 0;
}