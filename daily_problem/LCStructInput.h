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

using namespace std;
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
public:
    ~LCFormat() {
        for(TreeNode* root : treeBuff) {
            deleteTree(root);
        }
        for(ListNode* head : listBuff) {
            deleteList(head);
        }
    }

    void read(vector<int>& v) {
        string s;
        readline(s);
        int n = s.size();
        int i = 1;
        while(i < n - 1) {
            while(i < n - 1 && !isDigit(s[i])) ++i;
            if(i < n - 1) {
                int now = 0;
                while(i < n - 1 && isDigit(s[i])) {
                    now = now * 10 + s[i] - '0';
                    ++i;
                }
                v.emplace_back(now);
            }
        }
    }

    void read(vector<string>& vs) {
        string s;
        readline(s);
        int n = s.size(), i = 1;
        while(i < n - 1) {
            while(i < n - 1 && (s[i] == ',' || s[i] == ' ')) ++i;
            if(i < n - 1) {
                string now = "";
                while(i < n - 1 && (s[i] != ',' && s[i] != ' ')) {
                    now.push_back(s[i]);
                    ++i;
                }
                vs.emplace_back(now);
            }
        }
    }

    ListNode* readList() {
        vector<int> v;
        read(v);
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

    TreeNode* readTree() {
        vector<string> vs;
        read(vs);
        int n = vs.size();
        if(n == 0 || vs[0] == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(vs[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;
        while(i < n) {
            TreeNode* cur = q.front();
            q.pop();
            if(vs[i] != "null") {
                cur->left = new TreeNode(stoi(vs[i]));
                q.push(cur->left);
            }
            ++i;
            if(i < n) {
                if(vs[i] != "null") {
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
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur == nullptr) cout << "null,";
            else {
                cout << cur->val << ",";
                q.push(cur->left);
                q.push(cur->right);
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