#include <bits/stdc++.h>

using namespace std;

bool is_power_of_two(unsigned int n) {
	/*
	@brief: n是否为2的整数次方
	@param: 
	@return: 是 返回true
			 否 返回false
	*/
	return ((n & (n - 1)) == 0);
}


void swap(unsigned int& a, unsigned int& b)
{	/*
	@brief: 交换两个数，不申请额外空间
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