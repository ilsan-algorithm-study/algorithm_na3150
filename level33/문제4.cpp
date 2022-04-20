#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int parent[10]; //DAT ����

int getBoss(int ch) {

	if (parent[ch] == 0) return ch; //�ڽ��� ������ ���
	int ret = getBoss(parent[ch]); //�θ��� ��带 ã�� �ö�
	parent[ch] = ret;
	return ret;
}

void setUnion(char a, char b) { //�׷츸���(�߰�)
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
	int N, K; //ǰ�� ����, ��� ����
	cin >> N >> K;
	char a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		//�� �� ����
		if (a < 'A' && b < 'A')
			setUnion(a, b);
		//����1�� + ����1��
		else {
			if (a >= 'A') parent[b-'0'] = a; //a�� ����
			else parent[a-'0'] = b; //b�� ����
		}
	}
	for (int i = 1; i <= K; i++)
		cout << (char)getBoss(parent[i]);
	return 0;
}