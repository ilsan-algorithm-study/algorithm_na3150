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
	//불에 구우면 2배, 다 익으면 뒤집기
	for (int i = 0; i < N; i++)
		P = run(P);
	cout << P;
	return 0;
}