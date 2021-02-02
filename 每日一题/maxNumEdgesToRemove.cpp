/*
* @Author: wilson_t
* @Date:   2021-01-27 12:08:40
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-27 12:09:59
*/
/*
* 题目[困难]：
Alice 和 Bob 共有一个无向图，其中包含 n 个节点和 3  种类型的边：
类型 1：只能由 Alice 遍历。
类型 2：只能由 Bob 遍历。
类型 3：Alice 和 Bob 都可以遍历。
给你一个数组 edges ，其中 edges[i] = [typei, ui, vi] 表示节点 ui 和 vi 之间存在类型为 typei 的双向边。
请你在保证图仍能够被 Alice和 Bob 完全遍历的前提下，找出可以删除的最大边数。
如果从任何节点开始，Alice 和 Bob 都可以到达所有其他节点，则认为图是可以完全遍历的。
返回可以删除的最大边数，如果 Alice 和 Bob 无法完全遍历图，则返回 -1 。

提示：
1 <= n <= 10^5
1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
edges[i].length == 3
1 <= edges[i][0] <= 3
1 <= edges[i][1] < edges[i][2] <= n
所有元组 (typei, ui, vi) 互不相同

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable
 */
const int maxn = 100005;
int faA[maxn], faB[maxn];
class Solution {
public:
    int find(int fa[], int x) {
        return x == fa[x] ? x : fa[x] = find(fa, fa[x]);
    }

    bool merge(int fa[], int x, int y) {
        int fx = find(fa, x), fy = find(fa, y);
        if(fx != fy) {
            if(fx > fy) swap(fx, fy);
            fa[fy] = fx;
            return true;
        }
        return false;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        iota(faA, faA + n + 1, 0);
        iota(faB, faB + n + 1, 0);
        int count = 0;
        for(auto& e : edges) {
            if(e[0] == 3) {
                bool flag1 = merge(faA, e[1], e[2]), flag2 = merge(faB, e[1], e[2]);
                if(!flag1 && !flag2) {
                    ++count;
                }
            }
        }
        for(auto& e : edges) {
            if(e[0] == 1) {
                if(!merge(faA, e[1], e[2])) ++count;
            } else if(e[0] == 2) {
                if(!merge(faB, e[1], e[2])) ++count;
            }
        }
        int fx = find(faA, 1);
        for(int i = 2; i <= n; ++i) if(find(faA, i) != fx) return -1;
        fx = find(faB, 1);
        for(int i = 2; i <= n; ++i) if(find(faB, i) != fx) return -1;
        return count;
    }
};