#include <iostream>
#include <vector>
#include <string>
using namespace std;

int run(int a)
{
	string result = to_string(a * 2);
	reverse(result.begin(), result.end());
	return stoi(result);
}

int main()
{
	int P, N;
	cin >> P >> N;
	//�ҿ� ����� 2��, �� ������ ������
	for (int i = 0; i < N; i++)
		P = run(P);
	cout << P;
	return 0;
}