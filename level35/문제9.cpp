#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
int Min = 21e8;
string str;
int charges[7] = { 15,20,44,22,55,16,45 };
int sum;

void run(int count, int nSum)
{
	if (count == n) {
		if ((sum - nSum) % 10 == 0) {
			if (nSum < Min) Min = nSum;
		}
		return;
	}
	for (int i = 0; i < str.length(); i++)
		run(count + 1, nSum + charges[str[i] - 'a']);
}

int main()
{
	cin >> str;
	cin >> n;
	for (int i = 0; i < str.length(); i++)
		sum += charges[str[i] - 'a'];
	run(0, 0);
	cout << sum - Min;
	return 0;
}
