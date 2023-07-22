#include<bits/stdc++.h>
using namespace std;

/*
题目：
第一行输入一个正整数，代表数组长度
第二行输入a数组
第三行输入b数组
要求： 对于a数组中，通过翻转区间，使其和数组b相同。共有多少种解法？

输入示例：
4
1 2 3 1
1 3 2 1

*/
int main() {
	int length;
	cin >> length;
	string s1;
	for (int i = 0; i < length; i++) {
		char tmp;
		cin >> tmp;
		s1.push_back(tmp);
	}
	string s2;
	for (int i = 0; i < length; i++) {
		char tmp;
		cin >> tmp;
		s2.push_back(tmp);
	}
	int count = 0;
	for (int i = 0;i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			string s3 = s1;
			reverse(s3.begin()+i, s3.begin()+j+1);
			if (s3 == s2) {
				count++;
			}
		}
	}
	std::cout << count;
	return 0;
}
