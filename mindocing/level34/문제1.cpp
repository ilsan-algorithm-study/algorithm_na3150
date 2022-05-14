#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[10] = { 4,4,5,7,8,10,20,22,23,24 };
int flag;

void BS(int start, int end, int target)
{
	int mid = (start + end) / 2;
	if (arr[mid] == 10) {
		flag = 1;
		return;
	}
	if (start > end) return;
	if (arr[mid] < target) BS(mid + 1, end, target);
	else BS(start, mid - 1, target);
}

int main()
{
	int n;
	cin >> n;
	BS(0, 9, n);
	if (flag) cout << "O";
	else cout << "X";
	return 0;
}