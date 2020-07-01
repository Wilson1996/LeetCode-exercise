/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-11 17:42:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-12 16:38:04
*/
/*********************************************************
* 题目[中等]：
实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。

示例:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 true
trie.search("app");     // 返回 false
trie.startsWith("app"); // 返回 true
trie.insert("app");
trie.search("app");     // 返回 true

说明:
你可以假设所有的输入都是由小写字母 a-z 构成的。
保证所有输入均为非空字符串。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool isLeaf;
    TrieNode() : isLeaf(false) {}
};

class Trie
{
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* it = root;
        for(char c : word)
        {
            if(it->children.count(c) == 0)
            {
                it->children[c] = new TrieNode();
            }
            it = it->children[c];
        }
        it->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* it = root;
        for(char c : word)
        {
            if(it->children.count(c) == 0) return false;
            it = it->children[c];
        }
        return it->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* it = root;
        for(char c : prefix)
        {
            if(it->children.count(c) == 0) return false;
            it = it->children[c];
        }
        return true;
    }
};

//方法二
struct TrieNode
{
    TrieNode* children[26];
    // unordered_map<char, TrieNode*> children;
    bool isLeaf;
    TrieNode() : isLeaf(false) {
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie
{
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* it = root;
        for(char c : word)
        {
            if(it->children[c-'a'] == nullptr)
            {
                it->children[c-'a'] = new TrieNode();
            }
            it = it->children[c-'a'];
        }
        it->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode* it = root;
        for(char c : word)
        {
            if(it->children[c-'a'] == nullptr) return false;
            it = it->children[c-'a'];
        }
        return it->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode* it = root;
        for(char c : prefix)
        {
            if(it->children[c-'a'] == nullptr) return false;
            it = it->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */