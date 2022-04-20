#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int parent[10]; //DAT 저장

int getBoss(int ch) {

	if (parent[ch] == 0) return ch; //자신이 보스인 경우
	int ret = getBoss(parent[ch]); //부모의 노드를 찾아 올라감
	parent[ch] = ret;
	return ret;
}

void setUnion(char a, char b) { //그룹만들기(추가)
	int A = a - '0';
	int B = b - '0';
	if (parent[A] >= 'A') parent[B] = parent[A];
	else if (parent[B] >= 'A') parent[A] = parent[B];
	else { 
		parent[A] = B;
		parent[B] = A;
	}
}

int main()
{
	int N, K; //품목 개수, 고기 개수
	cin >> N >> K;
	char a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		//둘 다 숫자
		if (a < 'A' && b < 'A')
			setUnion(a, b);
		//숫자1개 + 문자1개
		else {
			if (a >= 'A') parent[b-'0'] = a; //a가 문자
			else parent[a-'0'] = b; //b가 문자
		}
	}
	for (int i = 1; i <= K; i++)
		cout << (char)getBoss(parent[i]);
	return 0;
}