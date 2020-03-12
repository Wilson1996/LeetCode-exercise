/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-12 10:29:11
* @Last Modified by:   Williss.T
* @Last Modified time: 2020-03-12 14:28:53
*/

/****************************************************************
* 题目[简单]：
对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1 次或多次）时，
我们才认定 “T 能除尽 S”。返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。

* 示例 1：
输入：str1 = "ABCABC", str2 = "ABC"
输出："ABC"

* 示例 2：
输入：str1 = "ABABAB", str2 = "ABAB"
输出："AB"

* 示例 3：
输入：str1 = "LEET", str2 = "CODE"
输出：""
 
* 提示：
1 <= str1.length <= 1000
1 <= str2.length <= 1000
str1[i] 和 str2[i] 为大写英文字母
****************************************************************/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//求最大公约数（辗转相除法）
int gcd_1(int a, int b)
{
	return b == 0 ? a : gcd_1(b, a % b);
}
int gcd_2(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}
class Solution
{
public:
	static string gcdOfStrings(string str1, string str2)
	{
		if(str1 + str2 != str2 + str1)
			return "";
		return str1.substr(0, __gcd(str1.length(), str2.length()));
	}
};

int main(int argc, char* argv[])
{
	string s1 = "ABABABAB";
	string s2 = "ABAB";
	cout << Solution::gcdOfStrings(s1, s2) << endl;
	return 0;
}