#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//union find: ������ Ʈ���� ���� ������ ������ �׷����� ����
//�θ� �ڽ� ������ �������. �׷����� �ƴ��� ���и� �߿�
//DAT�� �θ� ���

char parent[100]; //DAT ����

char getBoss(char ch) {

	if (parent[ch] == 0) return ch; //�ڽ��� ������ ���
	int ret = getBoss(parent[ch]); //�θ��� ��带 ã�� �ö�
	parent[ch] = ret; 
	return ret;
}

void setUnion(char c1, char c2) { //�׷츸���(�߰�)

	int a = getBoss(c1);
	int b = getBoss(c2);

	//������ �ٸ� ��� = �ٸ� �׷��� ���
	if (a != b)parent[b] = a;
}

int main()
{
	int n;
	cin >> n;
	char a, b;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (getBoss(a) == getBoss(b)) { //������ ���� ���(���� �׷�)
			flag = 1;
		}
		else setUnion(a, b);
	}
	if (flag == 0) cout << "�̹߰�";
	else cout << "�߰�";
	return 0;
}