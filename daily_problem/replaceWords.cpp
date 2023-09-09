/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-12 14:38:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-12 16:59:25
*/
/*********************************************************
* 题目[中等]：
在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成
另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，
跟随着单词 other(其他)，可以形成新的单词 another(另一个)。
现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继
承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。
你需要输出替换之后的句子。

示例：
输入：dict(词典) = ["cat", "bat", "rat"] sentence(句子) = "the cattle was rattled by the battery"
输出："the cat was rat by the bat"

提示：
输入只包含小写字母。
1 <= dict.length <= 1000
1 <= dict[i].length <= 100
1 <= 句中词语数 <= 1000
1 <= 句中词语长度 <= 1000
*********************************************************/
class Trie
{
private:
    Trie* children[26];
    string str;
    bool isLeaf;
public:
    /** Initialize your data structure here. */
    Trie() : isLeaf(false)
    {
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie* it = this;
        string tmp;
        for(char c : word)
        {
            int idx = c - 'a';
            if(it->children[idx] == nullptr)
            {
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
    bool search(string word)
    {
        Trie* it = this;
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
        Trie* it = this;
        for(char c : prefix)
        {
            if(it->children[c-'a'] == nullptr) return false;
            it = it->children[c-'a'];
        }
        return true;
    }
    // bool canReplace()
    string replace(string word)
    {
        Trie* it = this;
        for(char c : word)
        {
            if(it->children[c-'a'] == nullptr || it->isLeaf) break;
            it = it->children[c-'a'];
        }
        return it->isLeaf ? it->str : word;
    }
};

vector<string> regexsplit(const string& input, const string& pattern)
{
    regex re(pattern);
    sregex_token_iterator p(input.begin(), input.end(), re, -1);
    sregex_token_iterator end;
    vector<string> vec;
    while (p != end)
        vec.emplace_back(*p++);
    return vec;
}

class Solution
{
public:
    string replaceWords(vector<string>& dict, string sentence)
    {
        if(sentence == "") return "";
        Trie trie;
        for(auto& w : dict) trie.insert(w);
        vector<string> slist = regexsplit(sentence, " ");
        string res = trie.replace(slist[0]);
        int n = slist.size();
        for(int i = 1; i < n; ++i)
        {
            res += " " + trie.replace(slist[i]);
        }
        return res;
    }
};