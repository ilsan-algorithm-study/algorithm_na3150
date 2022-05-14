#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

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
	//�׷� ����
	setUnion('A', 'B');
	setUnion('B', 'C');
	setUnion('E', 'F');
	setUnion('F', 'D');
	setUnion('I', 'J');
	setUnion('H', 'G');
	int n;
	cin >> n;
	char a, b;
	int gcnt = 4;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (getBoss(a) != getBoss(b)) {
			setUnion(a, b);
			gcnt--; //�׷� ���� ������ -1
		}
	}
	cout << gcnt <<"��";
	return 0;
}