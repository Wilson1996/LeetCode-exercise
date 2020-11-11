/*
* @Author: wilson_t
* @Date:   2020-11-05 11:10:56
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-06 11:04:32
*/
/*
* 题目[中等]：
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。

说明:
如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: 0
解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
*/
class Solution {
public:
    bool check(const string& a, const string& b) {
        int diff = 0, n = a.size();
        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i]) diff++;
            if(diff > 1) return false;
        }
        return diff == 1;
    };

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size(), target = -1;
        wordList.emplace_back(beginWord);
        unordered_map<string, int> mp;
        unordered_set<string> st(wordList.begin(), wordList.end());
        for(int i = 0; i <= n; ++i) {
            mp[wordList[i]] = i;
        }
        if(mp.find(endWord) == mp.end()) return 0;
        target = mp[endWord];

        // //建图复杂度：O(nL)
        // vector<vector<int>> adj(n+1);
        // for(int i = 0; i <= n; ++i){
        //     string& word = wordList[i];
        //     int len = word.size();
        //     for(int j = 0; j < len; ++j){
        //         char tmp = word[j];
        //         for(char c = 'a'; c <= 'z'; ++c){
        //             if(c == tmp) continue;
        //             word[j] = c;
        //             if(mp.find(word) != mp.end()){
        //                 adj[i].emplace_back(mp[word]);
        //                 adj[mp[word]].emplace_back(i);
        //             }
        //         }
        //         word[j] = tmp;
        //     }
        // }

        //双向bfs
        queue<int> qf, qe;
        qf.push(n);
        qe.push(target);
        vector<int> distf(n + 1, INT_MAX), diste(n + 1, INT_MAX);
        distf[n] = 0;
        diste[target] = 0;
        // st.erase(beginWord), st.erase(endWord);
        queue<int>* q[2];
        vector<int>* dist[2];
        while(!qf.empty() && !qe.empty()) {
            //size小的先遍历
            if(qf.size() <= qe.size()) {
                q[0] = &qf;
                q[1] = &qe;
                dist[0] = &distf;
                dist[1] = &diste;
            } else {
                q[1] = &qf;
                q[0] = &qe;
                dist[1] = &distf;
                dist[0] = &diste;
            }
            for(int k = 0; k < 2; ++k) {
                int size = q[k]->size();
                for(int _ = 0; _ < size; ++_) {
                    int cur = q[k]->front();
                    if((*dist[1 - k])[cur] != INT_MAX) return ((*dist[0])[cur] + (*dist[1])[cur]) + 1;
                    q[k]->pop();
                    // for(const int& v : adj[cur]){
                    //     if((*dist[k])[v] == INT_MAX){
                    //         (*dist[k])[v] = (*dist[k])[cur] + 1;
                    //         q[k]->push(v);
                    //     }
                    // }

                    //不用先建图，效率会提高
                    string& word = wordList[cur];
                    int len = word.size();
                    for(int j = 0; j < len; ++j) {
                        char tmp = word[j];
                        for(char c = 'a'; c <= 'z'; ++c) {
                            if(c == tmp) continue;
                            word[j] = c;
                            if(st.find(word) != st.end() && (*dist[k])[mp[word]] == INT_MAX) {
                                (*dist[k])[mp[word]] = (*dist[k])[cur] + 1;
                                q[k]->push(mp[word]);
                            }
                        }
                        word[j] = tmp;
                    }
                }
            }
        }
        return 0;
    }
};