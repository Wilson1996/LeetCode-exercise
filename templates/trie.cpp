/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-12 23:36:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-12 23:36:19
*/
#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    //最后一个孩子节点用来存储字符串
    Trie* children[26];
    string str;
    bool isLeaf;
public:
    /** Initialize your data structure here. */
    Trie() : isLeaf(false) {
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* it = this;
        string tmp;
        for(char c : word) {
            int idx = c - 'a';
            if(it->children[idx] == nullptr) {
                it->children[idx] = new Trie();
                tmp = tmp + c;
                it->children[idx]->str = tmp;
            }
            tmp = it->children[idx]->str;
            it = it->children[idx];
        }
        it->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* it = this;
        for(char c : word) {
            if(it->children[c - 'a'] == nullptr) return false;
            it = it->children[c - 'a'];
        }
        return it->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* it = this;
        for(char c : prefix) {
            if(it->children[c - 'a'] == nullptr) return false;
            it = it->children[c - 'a'];
        }
        return true;
    }
    // bool canReplace()
    string replace(string word) {
        Trie* it = this;
        for(char c : word) {
            if(it->children[c - 'a'] == nullptr || it->isLeaf) break;
            it = it->children[c - 'a'];
        }
        return it->isLeaf ? it->str : word;
    }
};

// binary num trie
class Trie01 {
private:
    //最后一个孩子节点用来存储字符串
    Trie* children[2];
    int num = 0;
    int min_num = (1 << 21);
    int max_num = 0;
    int count = 0;
    bool isLeaf;
public:
    /** Initialize your data structure here. */
    Trie() : isLeaf(false) {
        for(int i = 0; i < 2; ++i) {
            children[i] = nullptr;
        }
        num = 0;
        min_num = (1 << 21);
    }
    /** Inserts a integer into the trie. */
    void insert(int x) {
        Trie* it = this;
        int tmp = 0;
        for (int i = 20; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if(it->children[bit] == nullptr) {
                it->children[bit] = new Trie();
                tmp += (bit << i);
                it->children[bit]->num = tmp;
                it->children[bit]->min_num = min(it->children[bit]->min_num, x);
                it->children[bit]->max_num = max(it->children[bit]->max_num, x);
            }
            tmp = it->children[bit]->num;
            it->min_num = min(it->min_num, x);
            it->max_num = max(it->max_num, x);
            it = it->children[bit];
        }
        it->isLeaf = true;
    }

    /** Returns if the integer is in the trie. */
    bool search(int x) {
        Trie* it = this;
        for (int i = 20; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if(it->children[bit] == nullptr) return false;
            it = it->children[bit];
        }
        return it->isLeaf;
    }
    
    int max_xor(int x, int mi) {
        Trie* it = this;
        for (int i = 20; i >= 0; --i) {
            int bit = (x >> i) & 1;
            int mi_bit = (mi >> i) & i;
            if (it->children[1 - bit] != nullptr && it->children[1 - bit]->max_num >= mi) {
                it = it->children[1 - bit];
            } else if (it->children[bit] != nullptr) {
                it = it->children[bit];
            } else {
                return -1;
            }
        }
        return it->num ^ x;
    }
 private:
    
};


class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        Trie trie;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            int y = nums[i];
            res = max(res, trie.max_xor(y, (y + 1) / 2));
            trie.insert(y);
        }
        return res;
    }
};