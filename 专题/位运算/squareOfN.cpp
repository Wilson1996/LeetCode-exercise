/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-27 19:12:50
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-27 19:34:33
*/
/*********************************************************
求解m的n次方
*********************************************************/
#include <iostream>

using namespace std;

int _pow(int m, int n)
{
	int sum = 1;
	while(n != 0) 
	{
		if(n & 1 == 1)
		{
			sum *= m;
		}
		m *= m;
		n >>= 1;
	}
	return sum;
}

int main(int argc, char * argv[])
{
	cout << _pow(4,4) << endl;
	return 0;
}