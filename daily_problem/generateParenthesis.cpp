/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-09 09:49:42
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-10 09:49:45
*/
/*********************************************************
* 题目[中等]：
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且有效的括号组合。

示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*********************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
	void backtrack(vector<string>& ans, string& cur, int open, int close, int n)
	{
		if (cur.size() == n * 2)
		{
			ans.push_back(cur);
			return;
		}
		if (open < n)
		{
			cur.push_back('(');
			backtrack(ans, cur, open + 1, close, n);
			cur.pop_back();
		}
		if (close < open)
		{
			cur.push_back(')');
			backtrack(ans, cur, open, close + 1, n);
			cur.pop_back();
		}
	}
public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		string current;
		backtrack(result, current, 0, 0, n);
		return result;
	}
};

int main(int argc, char* argv[])
{
	Solution soluter;
	vector<string> result = soluter.generateParenthesis(3);
	for(auto &s : result)
	{
		cout << s << endl;
	}
	return 0;
}