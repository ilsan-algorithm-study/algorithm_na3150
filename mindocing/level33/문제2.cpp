#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

char parent[100]; //DAT 저장

char getBoss(char ch) {

	if (parent[ch] == 0) return ch; //자신이 보스인 경우
	int ret = getBoss(parent[ch]); //부모의 노드를 찾아 올라감
	parent[ch] = ret;
	return ret;
}

void setUnion(char c1, char c2) { //그룹만들기(추가)

	int a = getBoss(c1);
	int b = getBoss(c2);

	//보스가 다른 경우 = 다른 그룹인 경우
	if (a != b)parent[b] = a;
}

int main()
{
	//그룹 생성
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
			gcnt--; //그룹 묶일 때마다 -1
		}
	}
	cout << gcnt <<"개";
	return 0;
}