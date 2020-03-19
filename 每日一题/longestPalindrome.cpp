/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-19 08:16:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-19 08:50:15
*/
/*********************************************************
* 题目[简单]：
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
注意:
假设字符串的长度不会超过 1010。

示例 1:
输入:
"abccccdd"
输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*********************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	static int longestPalindrome(string s)
	{
		int hash_ch[52] = {0};
		for(char ch : s)
		{
			if(ch >= 'A' && ch <= 'Z')
				++hash_ch[ch - 'A'];
			else if(ch >= 'a' && ch <= 'z')
				++hash_ch[ch - 'a' + 26];
		}
		int maxLen = 0;
		for(int i = 0; i < 52; ++i)
		{
			maxLen += (hash_ch[i]) / 2 * 2;
		}
		if(maxLen < s.length())
			++maxLen;
		return maxLen;
	}
};

int main(int argc, char* argv[])
{
	string s1 = "abccccdd";
	cout << Solution::longestPalindrome(s1) << endl;
	return 0;
}