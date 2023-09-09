/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-30 09:01:01
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-30 10:04:09
*/
/*********************************************************
* 题目[简单]：
0,1,,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字。
求出这个圆圈里剩下的最后一个数字。例如，0、1、2、3、4这5个数字组成一个圆圈，
从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。

示例 1：
输入: n = 5, m = 3
输出: 3

示例 2：
输入: n = 10, m = 17
输出: 2

限制：
1 <= n <= 10^5
1 <= m <= 10^6
*********************************************************/
#include <iostream>
#include <list>
using namespace std;

class Solution
{
public:
	//链表模拟，时间复杂度较高
	static int lastRemaining_1(int n, int m)
	{
		if(n < 1 || m < 1)
			return -1;
		list<int> JosephRing;
		for(int i = 0; i < n; ++i)
		{
			JosephRing.push_back(i);
		}
		// auto iter = JosephRing.begin();
		list<int>::iterator iter = JosephRing.begin();
		while(JosephRing.size() > 1)
		{
			for(int i = 1; i < m; ++i)
			{
				++iter;
				if(iter == JosephRing.end())
					iter = JosephRing.begin();
			}
			auto toDel = iter++;
			if(iter == JosephRing.end())
				iter = JosephRing.begin();
			JosephRing.erase(toDel);
		}
		return *(iter);
	}
	//数学方法
	static int lastRemaining_2(int n, int m) {
        if(n < 1 || m < 1)
		    return -1;
        int last = 0;
        for(int i = 2; i <= n; ++i)
        {
            last = (last + m) % i;
        }
        return last;
    }
};

int main(int argc, char* argv[])
{
	cout << Solution::lastRemaining_2(70866, 116922) << endl;
	return 0;
}