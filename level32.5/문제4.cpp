#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int number;
	string range;
	int start=1, end=50;
	for (int i = 0; i < n; i++)
	{
		cin >> number >> range;
		if (range == "DOWN") end = min(end, number);
		else start = max(start, number);
		if (start > end) {
			cout << "ERROR";
			return 0;
		}
	}
	if (end - start == 2) cout << start + 1; //정답이 1개로 좁혀진 경우
	else if (end - start == 1) cout << start;
	else cout << start+1 << " ~ " << end-1;
	return 0;
}