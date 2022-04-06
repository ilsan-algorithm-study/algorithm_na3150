#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string>vect(n);
	for (int i = 0; i < n; i++)
		cin >> vect[i];
	int cnt = 0;
	for (int i =0;i<n-1;i++)
		for (int j = i + 1; j < n; j++)
			if (vect[i] + vect[j] == "HITSMUSIC") cnt++;
	cout << cnt;
	return 0;
}