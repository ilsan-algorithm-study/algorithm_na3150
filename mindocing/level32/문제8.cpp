#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//모두 대문자
//첫 글자 대문자, 나머지 소문자

string change(string str)
{
	int len = str.length();
	int flag = 0;
	for (int i =1;i<len;i++) //두번째 문자부터 체크
		if (isupper(str[i])) {
			flag = 1; //대문자
			break;
		}
	//모두 소문자인 경우
	if (islower(str[0]) && flag == 0) {
		str[0] = toupper(str[0]);
		return str;
	}
	//첫글자만 대문자
	if (flag == 0) return str;
	//나머지
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
	return str;
}

int main()
{
	int n;
	cin >> n;
	vector<string>vect(n);
	for (int i = 0; i < n; i++) {
		cin >> vect[i];
		vect[i] = change(vect[i]);
	}
	sort(vect.begin(), vect.end());
	for (int i = 0; i < n; i++)
		cout << vect[i] << endl;
	return 0;
}