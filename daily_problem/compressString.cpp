/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-10 13:54:04
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-10 14:33:05
*/
/****************************************************************
* 题目[简单]：
* 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。
* 比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回
* 原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

* 示例1:
* 输入："aabcccccaaa"
* 输出："a2b1c5a3"

* 示例2:
* 输入："abbccd"
* 输出："abbccd"
* 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

* 提示：
* 字符串长度在[0, 50000]范围内。
*****************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	static string compressString(const string& S)
	{
		if(S.length() <= 2)
			return S;
		string result;
		int numOfChars = 0;
		for(int i = 0; i < S.length(); )
		{
			result += S[i];
			char char_curr = S[i];
			numOfChars = 1;
			++i;
			while(i < S.length() && S[i] == char_curr)
			{
				++i;
				++numOfChars;
			}
			result += std::to_string(numOfChars);
		}
		return result.length() < S.length() ? result : S;
	}
};

int main(int argc, char* argv[])
{
	// string str = "aabcccccaaa";
	string str = "abbccd";
	cout << Solution::compressString(str) << endl;
	return 0;
}