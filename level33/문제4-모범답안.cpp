#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int bucket[10];
int n, k; //ǰ�� ����, ��� ����

int getboss(int target)
{
	if (bucket[target] == 0) return target; //�ڽ��� ����
	int ret = getboss(bucket[target]);
	bucket[target] = ret;
	return ret;
}

void setunion(int ch1, int ch2)
{
	//������ ������ ���� Ȯ��
	int a = getboss(ch1);
	int b = getboss(ch2);
	if (a == b) return;
	bucket[b] = a;
}

int main()
{
	cin >> n >> k;
	char a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		int A = a - '0';
		int B = b - '0';
		if (a < 'A' && b < 'A') { //���� 2��
			if (bucket[A] >= 'A') {
				bucket[B] = bucket[A];
				continue;
			}
			else if (bucket[B] >= 'A') {
				bucket[A] = bucket[B];
				continue;
			}
			setunion(A, B);
		}
		else { //���� 1�� + ���� 1��
			if (a >= 'A') bucket[B] = a; //a�� ����
			else bucket[A] = b; //b�� ����
		}
	}

	for (int i = 1; i <= k; i++)
	{
		cout << (char)getboss(bucket[i]);
	}

	return 0;
}