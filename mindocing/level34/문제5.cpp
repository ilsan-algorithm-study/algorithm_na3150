#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int start = 1, end = N;
	int result;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (mid * mid <= N) {
			result = mid;
			start = mid + 1;
		}
		if (mid * mid > N) end = mid - 1;
	}
	cout << result;
	return 0;
}