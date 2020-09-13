/*
* @Author: wilson_t
* @Date:   2020-09-13 18:42:30
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-13 18:45:01
*/
/*********************************************************
* 题目[中等]:
给你一个points 数组，表示 2D 平面上的一些点，其中 points[i] = [xi, yi] 。
连接点 [xi, yi] 和点 [xj, yj] 的费用为它们之间的 曼哈顿距离 ：|xi - xj| + |yi - yj| ，其中 |val| 表示 val 的绝对值。
请你返回将所有点连接的最小总费用。只有任意两点之间 有且仅有 一条简单路径时，才认为所有点都已连接。

示例 1：
输入：points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
输出：20
解释：
我们可以按照上图所示连接所有点得到最小总费用，总费用为 20 。
注意到任意两个点之间只有唯一一条路径互相到达。

示例 2：
输入：points = [[3,12],[-2,5],[-4,1]]
输出：18

示例 3：
输入：points = [[0,0],[1,1],[1,0],[-1,1]]
输出：4

示例 4：
输入：points = [[-1000000,-1000000],[1000000,1000000]]
输出：4000000

示例 5：
输入：points = [[0,0]]
输出：0

提示：
1 <= points.length <= 1000
-106 <= xi, yi <= 106
所有点 (xi, yi) 两两不同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-to-connect-all-points
*********************************************************/
struct Edge {
    int from, to, w;
    Edge(int f, int t, int _w): from(f), to(t), w(_w) {}
};

bool cmp(const Edge& e1, const Edge& e2) {
    return e1.w < e2.w;
}

class Solution {
    int fa[1005];
public:
    int find(int p) {
        if(fa[p] == p) return p;
        return fa[p] = find(fa[p]);
    }

    bool join(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if(fx == fy) return false;
        if(fx > fy) swap(fx, fy);
        fa[fy] = fx;
        return true;
    }
    // kruskal 最小生成树算法
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n = pts.size();
        vector<Edge> edge;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                edge.emplace_back(i, j, abs(pts[i][0] - pts[j][0]) + abs(pts[i][1] - pts[j][1]));
            }
        }
        sort(edge.begin(), edge.end(), cmp);
        for(int i = 0; i < n; ++i) fa[i] = i;
        int m = edge.size(), cnt = n, res = 0;
        for(int i = 0; i < m && cnt > 1; ++i) {
            if(join(edge[i].from, edge[i].to)) {
                --cnt;
                res += edge[i].w;
            }
        }
        return res;
    }
};