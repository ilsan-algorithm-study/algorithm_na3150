#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    sort(str.begin(), str.end()); //사전순 정렬
    vector<char>vect(n);
    unordered_map<char, int>h;
    for (int i = str.length() - 1; i > str.length() - n; i--)
        h[str[i]]++;
    int Max = 0;
    char Alpha = 'A';
    for (char i = 'A'; i <= 'Z'; i++)
    {
        if (Max < h[i]) {
            Max = h[i];
            Alpha = i;
        }
    }
    cout << Alpha;
    return 0;
}