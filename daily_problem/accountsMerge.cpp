/*
* @Author: wilson_t
* @Date:   2021-01-18 14:26:53
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-18 14:28:06
*/
/*
* 题目[中等]：
给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。
现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，
它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。
合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按顺序排列的邮箱地址。账户本身可以以任意顺序返回。

示例 1：
输入：
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
输出：
[["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
解释：
第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。

提示：
accounts的长度将在[1，1000]的范围内。
accounts[i]的长度将在[1，10]的范围内。
accounts[i][j]的长度将在[1，30]的范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/accounts-merge
 */
class Solution {
public:
    int find(vector<int>& fa, int x) {
        return x == fa[x] ? x : fa[x] = find(fa, fa[x]);
    }
    bool merge(vector<int>& fa, int x, int y) {
        int fx = find(fa, x), fy = find(fa, y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        unordered_map<string, string> name;
        set<string> st;
        for(auto& vs : accounts) {
            int sz = vs.size();
            for(int i = 1; i < sz; ++i) {
                st.insert(vs[i]);
                name[vs[i]] = vs[0];
            }
        }
        vector<string> smp(st.size());
        int id = 0;
        for(const string& s : st) {
            mp[s] = id;
            smp[id] = s;
            ++id;
        }

        vector<int> fa(mp.size());
        iota(fa.begin(), fa.end(), 0);

        for(auto& vs : accounts) {
            int sz = vs.size();
            for(int i = 2; i < sz; ++i) merge(fa, mp[vs[i - 1]], mp[vs[i]]);
        }

        unordered_map<int, set<int>> group;

        for(int i = 0; i < fa.size(); ++i) {
            group[find(fa, i)].insert(i);
        }

        for(auto [k, st] : group) {
            vector<string> now;
            now.emplace_back(name[smp[*st.begin()]]);
            for(auto& x : st) {
                now.emplace_back(smp[x]);
            }
            res.push_back(now);
        }

        return res;
    }
};