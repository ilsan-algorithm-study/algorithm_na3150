#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int scores[4] = {0};
	for (int i = 0; i < N; i++) //내림차순
	{
		cin >> scores[3];
		for (int j = 3; j > 0; j--)
		{
			if (scores[j - 1] < scores[j])
				swap(scores[j - 1], scores[j]);
		}
	}
	cout << "금" << scores[0] <<endl;
	cout << "은" << scores[1] <<endl; 
	cout << "동" << scores[2] <<endl;
	return 0;
}