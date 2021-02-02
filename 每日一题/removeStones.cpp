/*
* @Author: wilson_t
* @Date:   2021-01-15 20:38:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-15 20:39:32
*/
/*
* 题目[中等]：
n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头。
如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头。
给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置，返回 可以移除的石子 的最大数量。

示例 1：
输入：stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
输出：5
解释：一种移除 5 块石头的方法如下所示：
1. 移除石头 [2,2] ，因为它和 [2,1] 同行。
2. 移除石头 [2,1] ，因为它和 [0,1] 同列。
3. 移除石头 [1,2] ，因为它和 [1,0] 同行。
4. 移除石头 [1,0] ，因为它和 [0,0] 同列。
5. 移除石头 [0,1] ，因为它和 [0,0] 同行。
石头 [0,0] 不能移除，因为它没有与另一块石头同行/列。

示例 2：
输入：stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
输出：3
解释：一种移除 3 块石头的方法如下所示：
1. 移除石头 [2,2] ，因为它和 [2,0] 同行。
2. 移除石头 [2,0] ，因为它和 [0,0] 同列。
3. 移除石头 [0,2] ，因为它和 [0,0] 同行。
石头 [0,0] 和 [1,1] 不能移除，因为它们没有与另一块石头同行/列。

示例 3：
输入：stones = [[0,0]]
输出：0
解释：[0,0] 是平面上唯一一块石头，所以不可以移除它。
 
提示：
1 <= stones.length <= 1000
0 <= xi, yi <= 104
不会有两块石头放在同一个坐标点上

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column
 */
class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;
public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }

    void unite(int x, int y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool findAndUnite(int x, int y) {
        int x0 = findset(x);
        int y0 = findset(y);
        if (x0 != y0) {
            unite(x0, y0);
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UF uf(n);
        int res = 0;
        vector<vector<int>> row(10005);
        vector<vector<int>> col(10005);
        for(int i = 0; i < n; ++i) {
            auto& p = stones[i];
            if(row[p[0]].size()) {
                if(uf.findAndUnite(row[p[0]][0], i)) ++res;
            } else {
                row[p[0]].push_back(i);
            }
            if(col[p[1]].size()) {
                if(uf.findAndUnite(col[p[1]][0], i)) ++res;
            } else {
                col[p[1]].push_back(i);
            }
        }
        return res;
    }
};