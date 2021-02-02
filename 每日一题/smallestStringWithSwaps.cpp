/*
* @Author: wilson_t
* @Date:   2021-01-11 10:12:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-11 10:14:28
*/
/*
* 题目[中等]：
给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。
你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

示例 1:
输入：s = "dcab", pairs = [[0,3],[1,2]]
输出："bacd"
解释： 
交换 s[0] 和 s[3], s = "bcad"
交换 s[1] 和 s[2], s = "bacd"

示例 2：
输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
输出："abcd"
解释：
交换 s[0] 和 s[3], s = "bcad"
交换 s[0] 和 s[2], s = "acbd"
交换 s[1] 和 s[2], s = "abcd"

示例 3：
输入：s = "cba", pairs = [[0,1],[1,2]]
输出："abc"
解释：
交换 s[0] 和 s[1], s = "bca"
交换 s[1] 和 s[2], s = "bac"
交换 s[0] 和 s[1], s = "abc"
 
提示：
1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s 中只含有小写英文字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-string-with-swaps
 */
const int maxn = 100005;
int fa[maxn];

class Solution {
public:
    int find(int x) {
        if(x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string res;
        unordered_map<int, multiset<char>> mp;
        int n = s.size();
        iota(fa, fa + n, 0);
        for(auto& p : pairs) {
            merge(p[0], p[1]);
        }
        for(int i = 0; i < n; ++i) {
            int fx = find(i);
            mp[fx].insert(s[i]);
        }
        for(int i = 0; i < n; ++i) {
            int fx = find(i);
            res.push_back(*(mp[fx].begin()));
            mp[fx].erase(mp[fx].begin());
        }
        return res;
    }
};