/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-28 11:52:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-28 14:49:02
*/
/*********************************************************
* 题目[中等]：
给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为
S = "time#bell#" 和 indexes = [0, 2, 5]。对于每一个索引，我们可以通过
从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。
那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

示例：
输入: words = ["time", "me", "bell"]
输出: 10
说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 
提示：
1 <= words.length <= 2000
1 <= words[i].length <= 7
每个单词都是小写字母 。
*********************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

namespace Method_1
{
class Solution
{
public:
	//方法一：逆序字典序
	static int minimumLengthEncoding(vector<string>& words)
	{
		int result = 0;
		for(string& Word : words) {reverse(Word.begin(), Word.end());}
		sort(words.begin(), words.end());
		for(int i = 0; i < words.size() - 1; ++i)
		{
			int len = words[i].size();
			if(words[i] == words[i + 1].substr(0, len)) continue;
			result += len + 1;
		}
		return result + words.back().size() + 1;
	}
};
}

namespace Method_2
{
//方法二：字典树
class TrieNode
{
	TrieNode* children[26];
public:
	int count;
	TrieNode()
	{
		for (int i = 0; i < 26; ++i) children[i] = NULL;
		count = 0;
	}
	TrieNode* get(char c)
	{
		if (children[c - 'a'] == NULL)
		{
			children[c - 'a'] = new TrieNode();
			count++;
		}
		return children[c - 'a'];
	}
};
class Solution
{
public:
	static int minimumLengthEncoding(vector<string>& words)
	{
		TrieNode* trie = new TrieNode();
		unordered_map<TrieNode*, int> nodes;
		for (int i = 0; i < (int)words.size(); ++i)
		{
			string word = words[i];
			TrieNode* cur = trie;
			for (int j = word.length() - 1; j >= 0; --j)
				cur = cur->get(word[j]);
			nodes[cur] = i;
		}
		int ans = 0;
		for (auto& node : nodes)
		{
			if (node.first->count == 0)
			{
				ans += words[node.second].length() + 1;
			}
		}
		return ans;
	}
};
}

int main(int argc, char* argv[])
{
	vector<string> words = {"time", "me", "bell"};
	cout << Method_2::Solution::minimumLengthEncoding(words) << endl;
	return 0;
}
