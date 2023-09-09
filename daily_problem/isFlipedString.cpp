/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-11 11:00:18
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-11 11:47:47
*/
/****************************************************************
* 题目[简单]：
* 字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成
*（比如，waterbottle是erbottlewat旋转后的字符串）。
*
* 示例1:
* 输入：s1 = "waterbottle", s2 = "erbottlewat"
* 输出：True
*
* 示例2:
* 输入：s1 = "aa", "aba"
* 输出：False
*
* 提示：
* 字符串长度在[0, 100000]范围内。
*
* 说明:
* 你能只调用一次检查子串的方法吗？
****************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	static bool isFlipedString(const string& s1, const string& s2)
	{
		if(s1.length() != s2.length())
			return false;
		string s3 = s2 + s2;
		return s3.find(s1) != string::npos;
	}
};

int main(int argc, char* argv[])
{
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	// cout << s1.compare(5, 6 , s2, 2, 6) << endl;
	Solution::isFlipedString(s1, s2) ? cout << "yes" << endl : cout << "no" << endl;
	return 0;
}