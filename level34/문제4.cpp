#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<string>map(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];
	int start = 0, end = N - 1;
	int maxX = -1, maxY = -1;
	while (start <= end) //X찾기
	{
		int mid = (start + end) / 2;
		if (map[mid][0] == '#' && mid > maxX) maxX = mid;
		if (map[mid][0] == '#') start = mid + 1;
		if (map[mid][0] == '0') end = mid - 1;
	}
	start = 0, end = N - 1;
	while (start <= end) //Y찾기
	{
		int mid = (start + end) / 2;
		if (map[maxX][mid] == '#' && mid > maxY) maxY = mid;
		if (map[maxX][mid] == '#') start = mid + 1;
		if (map[maxX][mid] == '0') end = mid - 1;
	}
	cout << maxX << " " << maxY;
	return 0;
}