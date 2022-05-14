#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int charge[9] = { 1,2,3,3,5,1,0,1,3 };
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += charge[i];
	int Min = sum;
	for (int i = 0; i < 9 - n; i++)
	{
		sum -= charge[i];
		sum += charge[i + n];
		if (sum < Min) Min = sum;
	}
	cout << Min;
	return 0;
}