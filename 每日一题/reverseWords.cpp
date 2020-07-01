/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-10 09:53:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-11 10:59:04
*/
/*********************************************************
* 题目[中等]：
给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"

示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
进阶：
请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
*********************************************************/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
	static string reverseWords(string s)
	{
		stack<string> S;
		int start, end;
		start = end = 0;
		bool hasStart = false;
		for(; end < s.size(); ++end)
		{
			if(!hasStart && s[end] != ' ')
			{
				start = end;
				hasStart = true;
			}
			else if(hasStart && s[end] == ' ')
			{
				hasStart = false;
				S.push(s.substr(start, end - start));
			}
		}
		if(hasStart && s.back() != ' ')
			S.push(s.substr(start, end - start));
		string result;
		if(!S.empty())
		{
			result.append(S.top());
			S.pop();
		}
		while(!S.empty())
		{
			result.push_back(' ');
			result.append(S.top());
			S.pop();
		}
		return result;
	}
};

int main(int argc, char* argv[])
{
	cout << Solution::reverseWords("  hello world!     ") << endl;
	return 0;
}