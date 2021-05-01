/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-12 15:05:55
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-20 19:20:31
*/
/*************************************************************
* 不用if等比较语句，计算两个整数的最大值
**************************************************************/	
#include <iostream>

using namespace std;

// a - b 有溢出的情况
int _max(int a, int b)
{
	int c = a - b;
	int k = (c >> (sizeof(int) * 8 - 1)) & 0x01;
	return a - k * c;
}

int main(int argc, char *argv[])
{
	cout << _max(0x7fffffff, -4) << endl;
	return 0;
}