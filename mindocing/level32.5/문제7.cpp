#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int arr[4][8];

int getRectangle(int x, int y)
{
	if (arr[x][y] == 0) return 0;
	int w = 7, h = x;
	for (int i = y; i < 8; i++) {//가장 긴 가로 찾기
		if (arr[x][i] == 0) {
			w = i - 1;
			break;
		}
	}
	for (int i = x+1; i < 4; i++) { //가장 긴 세로 찾기
		int flag = 0;
		for (int j = y; j <= w; j++)
			if (arr[i][j] == 0) flag = 1;
		if (flag == 0) h++;
	}
	int sum = 0;
	for (int i = x; i <= h; i++)
		for (int j = y; j <= w; j++)
			sum += arr[i][j];
	return sum;
}


int main()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> arr[i][j];
	int Max = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] >0 ) Max = max(Max,getRectangle(i, j));
		}
	cout << Max;
	return 0;
}