#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, citizen;
	cin >> N >> citizen;
	vector<vector<string>>vect(N);
	int num;
	string name;
	for (int i = 0; i < citizen; i++)
	{
		cin >> num >> name;
		vect[num].push_back(name);
	}
	int Max = 0;
	int maxIndex=0;
	for (int i = 0; i < N; i++)
	{
		if (vect[i].size() > Max) {
			Max = vect[i].size();
			maxIndex = i;
		}
	}
	for (int i = 0; i < vect[maxIndex].size(); i++)
		cout << vect[maxIndex][i] << " ";
	return 0;
}