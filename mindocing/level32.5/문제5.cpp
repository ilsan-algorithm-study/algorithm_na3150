#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//���ȣ�� �̿�

pair<int, string> arr[7] = {
    {3,">>"}, {2,">>"}, {1,"<<"}, {3,">>"},{2,"<<"},{0,"X"},{1,"<<"} };

void run(int index)
{
    if (arr[index].first == 0) {//�׷��� �߰��� ���
        cout << index << "��" << endl;
        return;
    }
    if (arr[index].second == "<<") run(index - arr[index].first);
    else run(index + arr[index].first);
    cout << index << "��" << endl;
}


int main()
{
    int index;
    cin >> index;
    run(index);
    return 0;
}