/*
* @Author: wilson_t
* @Date:   2020-08-18 17:39:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-18 21:25:30
*/
/*********************************************************
* 题目[困难]：
给定一个二维网格 board 和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母在一个单词中不允许被重复使用。

示例:
输入:
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
输出: ["eat","oath"]

说明:
你可以假设所有输入都由小写字母 a-z 组成。

提示:
你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？
前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    string str;
    bool isLeaf;
    TrieNode(): isLeaf(false) {
        str = "";
        for(int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Solution {
    vector<string> res;
    int m, n;
public:
    void dfs(vector<vector<char>>& board, TrieNode* p, int x, int y) {
        char c = board[x][y];
        if(c == '.' || p->children[c - 'a'] == nullptr) return;
        TrieNode* nxt = p->children[c - 'a'];
        if(nxt->str != "") {
            res.emplace_back(nxt->str);
            nxt->str = "";
        }
        board[x][y] = '.';
        if(x > 0) dfs(board, nxt, x - 1, y);
        if(x < m - 1) dfs(board, nxt, x + 1, y);
        if(y > 0) dfs(board, nxt, x, y - 1);
        if(y < n - 1) dfs(board, nxt, x, y + 1);
        board[x][y] = c;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        TrieNode* root = new TrieNode();
        for(auto& w : words) {
            TrieNode* cur = root;
            for(auto c : w) {
                int idx = c - 'a';
                if(cur->children[idx] == nullptr) {
                    cur->children[idx] = new TrieNode();
                }
                cur = cur->children[idx];
            }
            cur->str = w;
        }

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                dfs(board, root, i, j);
            }
        }
        return res;
    }
};