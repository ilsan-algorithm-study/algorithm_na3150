#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string str[3][3];

void wind(char strong)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (str[i][j].length() > 0) {
                int len = str[i][j].size();
                if (str[i][j][len - 1] <= strong) str[i][j].erase(len - 1, 1);
                else str[i][j][len - 1] -= strong - '0'; //강풍이 더 센 경우
            }
}

int getLeft()
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sum += str[i][j].length();
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int x, y;
    string s; //문자열로 처리
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> s;
        str[x][y] = s;
    }
    int num; //강풍 횟수
    cin >> num;
    char strong; //강풍의 세기
    for (int i = 0; i < num; i++)
    {
        cin >> strong;
        wind(strong);
    }

    cout << getLeft();
    return 0;
}