/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-06 15:53:08
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-07 00:28:21
*/
/*********************************************************
* 题目[困难]：
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*********************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minOf3(int a, int b, int c)
{
	int x = a < b ? a : b;
	return x < c ? x : c;
}
class Solution
{
public:
	//动态规划：
	//dp(i,j) = word1前i个与word2前j个转换的次数
	//			/ min(dp(i-1, j)+1, dp(i, j-1)+1, dp(i-1,j-1)) 	  	if word1[i] == word2[j]
	//dp(i,j) = |
	//	        \ min(dp(i-1, j), dp(i, j-1), dp(i-1,j-1)) + 1		otherwise
	//
	static int minDistance(string word1, string word2)
	{
		int m = word1.size();
		int n = word2.size();
		if(m * n == 0)
			return m + n;
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for(int i = 0; i <= m; ++i)
		{
			dp[i][0] = i;
		}
		for(int j = 0; j <= n; ++j)
		{
			dp[0][j] = j;
		}
		for(int i = 1; i <= m; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				// if(word1[i] == word2[j])
				// {
				// 	dp[i][j] = minOf3(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1]);
				// }
				// else
				// {
				// 	dp[i][j] = minOf3(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
				// }
				int left = dp[i - 1][j] + 1;
                int down = dp[i][j - 1] + 1;
                int left_down = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) 
                	left_down += 1;
                dp[i][j] = min(left, min(down, left_down));
			}
		}
		return dp[m][n];
	}
};
int main(int argc, char* argv[])
{
	cout << minOf3(1,3,2) << endl;
	cout << minOf3(10,-3,2) << endl;
	cout << Solution::minDistance("intention", "execution") << endl;
	return 0;
}