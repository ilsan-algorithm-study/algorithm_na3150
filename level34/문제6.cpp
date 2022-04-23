#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	priority_queue<double, vector<double>, greater<double>>heap; //ÃÖ¼ÒÈü
	int n;
	cin >> n;
	int count = 0; //²¨³½È½¼ö
	int a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		heap.push(a);
	}
	double gold1, gold2;
	while (true)
	{
		gold1 = heap.top();
		if (gold1 != (int)gold1) break;
		heap.pop();
		count++;
		gold2 = heap.top();
		if (gold2 != (int)gold2) break;
		heap.pop();
		count++;
		heap.push(gold2 * 2 + 0.5); //µ¹Àº 0.5 ´õÇØ¼­
	}
	cout << count;

	return 0;
}