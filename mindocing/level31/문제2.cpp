#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int>vect(n);
	for (int i = 0; i < n; i++) {
		cin >> vect[i];
	}
	int sum = 0; //���ӵ� 4ĭ�� ��
	for (int i = 0; i < 4; i++)
		sum += vect[i];
	int Min = sum;
	for (int i = 0; i < vect.size()-4; i++) {
		sum -= vect[i];
		sum += vect[i + 4];
		if (sum < Min) Min = sum;
	}
	cout << Min;
	return 0;
}