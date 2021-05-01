/*
 * author: williss
 * date: 2021.4.2
 * using tutorial:
     LCFormat lc;
     vector<int> v;
     lc.read(v);
     ListNode* head = lc.readList();
     TreeNode* root = lc.readTree();
     lc.print(head);
     lc.print(root);
     lc.preOrder(root);
     lc.inOrder(root);
     lc.postOrder(root);
 *
 */
#ifndef __LCSTRUCTINPUT_H
#define __LCSTRUCTINPUT_H
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <regex>
#include "debug.h"

using namespace std;

//序列化后null节点的表示方式
#define NULL_NODE "null"

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LCFormat {
private:
    set<TreeNode*> treeBuff;
    set<ListNode*> listBuff;
    void readline(string& s) {
        getline(cin >> ws, s);
    }
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    void deleteList(ListNode* head) {
        while(head != nullptr) {
            ListNode* nxt = head->next;
            delete head;
            head = nxt;
        }
    }

    void deleteTree(TreeNode* root) {
        if(root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    void makeVec(string& s, vector<int>& v) {
        v.clear();
        int n = s.size();
        int i = 1;
        while(i < n) {
            while(i < n && !isDigit(s[i])) ++i;
            if(i < n) {
                int now = 0;
                while(i < n && isDigit(s[i])) {
                    now = now * 10 + s[i] - '0';
                    ++i;
                }
                v.emplace_back(now);
            }
        }
    }
public:
    ~LCFormat() {
        for(TreeNode* root : treeBuff) {
            deleteTree(root);
        }
        for(ListNode* head : listBuff) {
            deleteList(head);
        }
    }

    vector<string> regexsplit(const string& input, const string& pattern) {
        regex re(pattern);
        sregex_token_iterator p(input.begin(), input.end(), re, -1);
        sregex_token_iterator end;
        vector<string> vec;
        while (p != end)
            vec.emplace_back(*p++);
        return vec;
    }

    void read(vector<int>& v) {
        string s;
        readline(s);
        makeVec(s, v);
    }

    //读入二维数组
    // 格式：[[1,2],[2,3,4]]
    void read(vector<vector<int>>& vv) {
        vv.clear();
        string s;
        readline(s);
        s.pop_back();
        int n = s.size(), i = 0;
        vector<int> vec;
        while(i < n) {
            string now = "";
            while(i < n && s[i] != ']') {
                now.push_back(s[i]);
                ++i;
            }
            if(now.size()) {
                makeVec(now, vec);
                vv.emplace_back(vec);
            }
            ++i;
        }
    }

    void read(vector<string>& vs) {
        string s;
        readline(s);
        int n = s.size(), i = 1;
        while(i < n - 1) {
            while(i < n - 1 && (s[i] == ',' || s[i] == ' ' || s[i] == '[' || s[i] == ']')) ++i;
            if(i < n - 1) {
                string now = "";
                while(i < n - 1 && (s[i] != ',' && s[i] != ' ' && s[i] != '[' && s[i] != ']')) {
                    now.push_back(s[i]);
                    ++i;
                }
                vs.emplace_back(now);
            }
        }
    }

    ListNode* makeList(vector<int>& v) {
        ListNode dummy(-1);
        ListNode* it = &dummy;
        for(int x : v) {
            it->next = new ListNode(x);
            it = it->next;
        }
        it->next = nullptr;
        listBuff.insert(dummy.next);
        return dummy.next;
    }

    ListNode* readList() {
        vector<int> v;
        read(v);
        // Debug() << "readList: " << v << "\n";
        ListNode* res = makeList(v);
        return res;
    }

    TreeNode* readTree() {
        vector<string> vs;
        read(vs);
        // Debug() << "vs: " << vs << "\n";
        int n = vs.size();
        if(n == 0 || vs[0] == NULL_NODE) return nullptr;
        TreeNode* root = new TreeNode(stoi(vs[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(i < n) {
            TreeNode* cur = q.front();
            q.pop();
            if(vs[i] != NULL_NODE) {
                cur->left = new TreeNode(stoi(vs[i]));
                q.push(cur->left);
            }
            ++i;
            if(i < n) {
                if(vs[i] != NULL_NODE) {
                    cur->right = new TreeNode(stoi(vs[i]));
                    q.push(cur->right);
                }
            }
            ++i;
        }
        treeBuff.insert(root);
        return root;
    }

    void print(ListNode* head) {
        ListNode* it = head;
        while(it != nullptr) {
            cout << it->val << "->";
            it = it->next;
        }
        cout << "null\n";
    }

    //layer traverse
    void print(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        cout << "[";
        int cnt = 0;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr) cout << ",null";
            else {
                if(cnt > 0) cout << ",";
                cout << cur->val;
                q.push(cur->left);
                q.push(cur->right);
                ++cnt;
            }
        }
        cout << "]\n";
    }

    void preOrder(TreeNode* root) {
        vector<int> v;
        std::function<void(TreeNode*)> dfs;
        dfs = [&](TreeNode * root) {
            if(!root) return;
            v.emplace_back(root->val);
            dfs(root->left);
            dfs(root->right);
        };
        dfs(root);
        cout << "[";
        for(int i = 0; i < (int)v.size(); ++i) {
            if(i == 0) cout << v[i];
            else {
                cout << ", " << v[i];
            }
        }
        cout << "]\n";
    }

    void inOrder(TreeNode* root) {
        vector<int> v;
        std::function<void(TreeNode*)> dfs;
        dfs = [&](TreeNode * root) {
            if(!root) return;
            dfs(root->left);
            v.emplace_back(root->val);
            dfs(root->right);
        };
        dfs(root);
        cout << "[";
        for(int i = 0; i < (int)v.size(); ++i) {
            if(i == 0) cout << v[i];
            else {
                cout << ", " << v[i];
            }
        }
        cout << "]\n";
    }

    void postOrder(TreeNode* root) {
        vector<int> v;
        std::function<void(TreeNode*)> dfs;
        dfs = [&](TreeNode * root) {
            if(!root) return;
            dfs(root->left);
            dfs(root->right);
            v.emplace_back(root->val);
        };
        dfs(root);
        cout << "[";
        for(int i = 0; i < (int)v.size(); ++i) {
            if(i == 0) cout << v[i];
            else {
                cout << ", " << v[i];
            }
        }
        cout << "]\n";
    }
};

#endif