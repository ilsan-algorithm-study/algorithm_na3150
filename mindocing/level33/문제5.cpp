#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int n;
int bucket[10];
int population[10];

int getboss(int target)
{
	if (bucket[target] == 0) return target; //자신이 보스
	int ret = getboss(bucket[target]);
	bucket[target] = ret;
	return ret;
}
void setunion(int ch1, int ch2)
{
	//보스가 같은지 부터 확인
	int a = getboss(ch1);
	int b = getboss(ch2);
	if (a == b) return;
	bucket[b] = a;
}

int getPopulation(char a) //동맹국 인구의 합
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (getboss(a - 'A') == getboss(i))
			count += population[i];
	return count;
}

int getAlly(char a) //동맹국의 수
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (getboss(a - 'A') == getboss(i))
			count++;
	return count;
}

int main()
{
	cin >> n;//국가의 수
	for (int i = 0; i < n; i++)
		cin >> population[i];
	int k; //상황의 수
	cin >> k;
	string sit;
	char a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> sit >> a >> b;
		if (sit == "alliance") setunion(a - 'A', b - 'A');
		else {
			if (getPopulation(a) > getPopulation(b)) n -= getAlly(b);
			else n -= getAlly(a);
		}
	}
	cout << n;
	return 0;
}
