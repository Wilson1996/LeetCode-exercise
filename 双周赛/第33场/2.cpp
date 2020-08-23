/*
* @Author: wilson_t
* @Date:   2020-08-23 12:56:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 13:11:38
*/
/*
给你一个 有向无环图 ， n 个节点编号为 0 到 n-1 ，以及一个边数组 edges ，其中 edges[i] = [fromi, toi] 表示一条从点  fromi 到点 toi 的有向边。
找到最小的点集使得从这些点出发能到达图中所有点。题目保证解存在且唯一。
你可以以任意顺序返回这些节点编号。

提示：
2 <= n <= 10^5
1 <= edges.length <= min(10^5, n * (n - 1) / 2)
edges[i].length == 2
0 <= fromi, toi < n
所有点对 (fromi, toi) 互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-vertices-to-reach-all-nodes
*/
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for(auto& e : edges) {
            inDegree[e[1]]++;
        }
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            if(inDegree[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};