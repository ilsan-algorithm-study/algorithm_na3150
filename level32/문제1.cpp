#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct temp {
	int a;
	char b;
};

int main()
{
	int n;
	cin >> n;
	vector<temp>vect(n);
	for (int i = 0; i < n; i++)
		cin >> vect[i].a >> vect[i].b;
	for (int i = 0; i < n - 1; i++) { //Insert Sort
		for (int j = i + 1; j > 0; j--)
		{
			if (vect[j - 1].a > vect[j].a) swap(vect[j - 1], vect[j]);
			else if (vect[j - 1].a == vect[j].a)
				if (vect[j - 1].b > vect[j].b) swap(vect[j - 1], vect[j]);
		}
	}
	for (int i = 0; i < n; i++)
		cout << vect[i].a << " " << vect[i].b << endl;
	return 0;
}