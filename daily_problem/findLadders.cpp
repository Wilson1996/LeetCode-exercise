/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-07 09:18:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-07 23:37:42
*/
/*********************************************************
* 题目[困难]：
给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。
转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。

说明:
如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: []

解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
	unordered_map<string, int> mp;
    vector<vector<int>> G;
    vector<vector<string>> res;
    vector<int> pre;
    vector<bool> vis;
public:
    void bfs(int head){
    	queue<int> Q;
    	Q.push(head);
    	bool found = false;
    	while (!Q.empty()){
    		int _size = Q.size();
    		while(_size--){
    			int cur = Q.front();
    			Q.pop();
    		}
    	}
    }
    bool similar(const string& a, const string& b){
    	int cnt = 0;
    	int n = a.length();
    	for(int i = 0; i < n; ++i){
    		if(a[i] != b[i]) ++cnt;
    		if(cnt > 1) return false;
    	}
    	return true;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
    	int idx = 0;
        for(auto& w : wordList) mp[w] = idx++;
        if(mp.find(beginWord) == mp.end()) {mp[beginWord] = idx++; wordList.push_back(beginWord);}
    	if(mp.find(endWord) == mp.end()) {mp[endWord] = idx++; wordList.push_back(endWord);}
        int n = wordList.size();
        G = vector<vector<int>>(n);
        vis = vector<bool>(n, false);
        pre = vector<int>(n);
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
            	if(similar(wordList[i], wordList[j])){
            		G[i].emplace_back(j);
            		G[j].emplace_back(i);
            	}
            }
        }
        bfs(mp[beginWord]);
        return res;
    }
};

int main(int argc, char* argv[])
{
	Solution soluter;

	return 0;
}