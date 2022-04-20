#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//union find: 동일한 트리에 묶여 있으면 동일한 그룹으로 간주
//부모 자식 순서는 상관없음. 그룹인지 아닌지 구분만 중요
//DAT로 부모 기록

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
	int n;
	cin >> n;
	char a, b;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (getBoss(a) == getBoss(b)) { //보스가 같은 경우(같은 그룹)
			flag = 1;
		}
		else setUnion(a, b);
	}
	if (flag == 0) cout << "미발견";
	else cout << "발견";
	return 0;
}