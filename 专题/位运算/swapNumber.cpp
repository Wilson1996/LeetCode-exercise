/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-27 19:01:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-27 19:06:34
*/
/*********************************************************
不使用辅助内存，交换两个整数
*********************************************************/
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	if(*a != *b)
	{
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}

int main(int argc, char * argv[])
{
	int x = 5;
	int y = 10;
	swap(&x, &y);
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	return 0;
}