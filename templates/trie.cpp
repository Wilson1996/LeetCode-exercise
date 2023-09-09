/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-12 23:36:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-12 23:36:19
*/
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
