#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str[5];
    for (int i = 0; i < 5; i++)
        cin >> str[i];
    int a, b;
    cin >> a >> b;
    sort(str[a].begin(), str[a].end());
    sort(str[b].begin(), str[b].end());
    for (int i = 0; i < 5; i++)
        cout << str[i][0] << " ";
    return 0;
}