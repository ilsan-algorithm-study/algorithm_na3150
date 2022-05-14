#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//��� �빮��
//ù ���� �빮��, ������ �ҹ���

string change(string str)
{
	int len = str.length();
	int flag = 0;
	for (int i =1;i<len;i++) //�ι�° ���ں��� üũ
		if (isupper(str[i])) {
			flag = 1; //�빮��
			break;
		}
	//��� �ҹ����� ���
	if (islower(str[0]) && flag == 0) {
		str[0] = toupper(str[0]);
		return str;
	}
	//ù���ڸ� �빮��
	if (flag == 0) return str;
	//������
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