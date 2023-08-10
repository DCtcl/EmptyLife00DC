#include <bits/stdc++.h>

using namespace std;

bool is_power_of_two(unsigned int n) {
	/*
	@brief: n�Ƿ�Ϊ2�������η�
	@param: 
	@return: �� ����true
			 �� ����false
	*/
	return ((n & (n - 1)) == 0);
}


void swap(unsigned int& a, unsigned int& b)
{	/*
	@brief: ���������������������ռ�
	@param: 
	@return: 
	*/
	a = a ^ b;    // a = a ^ b;
	b = a ^ b;    // b = a ^ b ^ b = a;
	a = a ^ b;    // a = a ^ b ^ a = b;
}





int main() {
	unsigned int a = 1, b = 2;
	swap(a, b);
	cout << a << b;;
	return 0;

}