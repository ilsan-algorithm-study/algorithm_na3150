#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1) cout << 21; //O(1)
	else if (n == 2) cout << 2; //O(n^2)
	else if (n == 3) cout << 2; //O(n^2)
	else cout << 2; //O(n^2)
	return 0;
}