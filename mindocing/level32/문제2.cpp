#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int scores[4] = {0};
	for (int i = 0; i < N; i++) //��������
	{
		cin >> scores[3];
		for (int j = 3; j > 0; j--)
		{
			if (scores[j - 1] < scores[j])
				swap(scores[j - 1], scores[j]);
		}
	}
	cout << "��" << scores[0] <<endl;
	cout << "��" << scores[1] <<endl; 
	cout << "��" << scores[2] <<endl;
	return 0;
}