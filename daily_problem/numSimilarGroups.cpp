/*
* @Author: wilson_t
* @Date:   2021-01-31 11:48:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-31 11:50:54
*/
/*
* 题目[困难]：
如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，
那么称 X 和 Y 两个字符串相似。如果这两个字符串本身是相等的，那它们也是相似的。
例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，
但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。
总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。
注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。形式上，对每个组而言，要确定一个单词在组中，
只需要这个词和该组中至少一个单词相似。
给你一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个字母异位词。
请问 strs 中有多少个相似字符串组？

示例 1：
输入：strs = ["tars","rats","arts","star"]
输出：2

示例 2：
输入：strs = ["omv","ovm"]
输出：1
 
提示：
1 <= strs.length <= 100
1 <= strs[i].length <= 1000
sum(strs[i].length) <= 2 * 104
strs[i] 只包含小写字母。
strs 中的所有单词都具有相同的长度，且是彼此的字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/similar-string-groups
 */
const int maxn = 2005;
int fa[maxn];
class Solution {
public:
    inline int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    inline bool merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        iota(fa, fa + n, 0);
        auto check = [&](string & s1, string & s2) {
            int m = s1.size(), diff = 0;
            for(int i = 0; i < m; ++i) {
                if(s1[i] != s2[i]) ++diff;
                if (diff > 2) return false;
            }
            return true;
        };
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int fi = find(i), fj = find(j);
                if (fi == fj) continue;
                if(check(strs[i], strs[j])) {
                    merge(i, j);
                    // if(fi > fj) swap(fi, fj);
                    // fa[fj]=fi;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < n; ++i) {
            if(fa[i] == i) ++res;
        }
        return res;
    }
};