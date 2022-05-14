#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Min = 21e8;
int charge;
int arr[3] = { 10,40,60 };

void run(int count, int sum)
{
	if (sum > charge) return;
	if (sum == charge) {
		if (count < Min) Min = count;
		return;
	}
	for (int i = 0; i < 3; i++)
		run(count + 1, sum + arr[i]);
}

int main()
{
	cin >> charge;
	run(0, 0);
	cout << Min;
	return 0;
}