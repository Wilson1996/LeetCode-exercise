/*
* @Author: wilson_t
* @Date:   2021-05-04 22:08:15
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-05-04 22:09:24
*/
/*
* 题目[困难]：
在一个小城市里，有 m 个房子排成一排，你需要给每个房子涂上 n 种颜色之一（颜色编号为 1 到 n ）。有的房子去年夏天已经涂过颜色了，所以这些房子不需要被重新涂色。
我们将连续相同颜色尽可能多的房子称为一个街区。（比方说 houses = [1,2,2,3,3,2,1,1] ，它包含 5 个街区  [{1}, {2,2}, {3,3}, {2}, {1,1}] 。）
给你一个数组 houses ，一个 m * n 的矩阵 cost 和一个整数 target ，其中：
houses[i]：是第 i 个房子的颜色，0 表示这个房子还没有被涂色。
cost[i][j]：是将第 i 个房子涂成颜色 j+1 的花费。
请你返回房子涂色方案的最小总花费，使得每个房子都被涂色后，恰好组成 target 个街区。如果没有可用的涂色方案，请返回 -1 。
 
示例 1：
输入：houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
输出：9
解释：房子涂色方案为 [1,2,2,1,1]
此方案包含 target = 3 个街区，分别是 [{1}, {2,2}, {1,1}]。
涂色的总花费为 (1 + 1 + 1 + 1 + 5) = 9。

示例 2：
输入：houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
输出：11
解释：有的房子已经被涂色了，在此基础上涂色方案为 [2,2,1,2,2]
此方案包含 target = 3 个街区，分别是 [{2,2}, {1}, {2,2}]。
给第一个和最后一个房子涂色的花费为 (10 + 1) = 11。

示例 3：
输入：houses = [0,0,0,0,0], cost = [[1,10],[10,1],[1,10],[10,1],[1,10]], m = 5, n = 2, target = 5
输出：5

示例 4：
输入：houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
输出：-1
解释：房子已经被涂色并组成了 4 个街区，分别是 [{3},{1},{2},{3}] ，无法形成 target = 3 个街区。
 
提示：
m == houses.length == cost.length
n == cost[i].length
1 <= m <= 100
1 <= n <= 20
1 <= target <= m
0 <= houses[i] <= n
1 <= cost[i][j] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/paint-house-iii
 */
const int inf = 0x3f3f3f3f;
class Solution {
    int f[105][105][25];
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //f[i][j][k]: 前i个房子中，组成j个group, 最后一个房子的颜色是k的最小花费
        memset(f, 0x3f, sizeof(f));
        if(houses[0] != 0) f[0][1][houses[0]] = 0;
        else {
            for(int k = 1; k <= n; ++k) {
                f[0][1][k] = cost[0][k - 1];
            }
        }
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j <= i + 1; ++j) {
                if(houses[i] != 0) {
                    for(int l = 1; l <= n; ++l) { //枚举i-1位置的颜色
                        if(l == houses[i]) {
                            f[i][j][houses[i]] = min(f[i][j][houses[i]], f[i - 1][j][l]);
                        } else {
                            f[i][j][houses[i]] = min(f[i][j][houses[i]], f[i - 1][j - 1][l]);
                        }
                    }
                } else {
                    for(int k = 1; k <= n; ++k) { // 枚举i位置的颜色
                        for(int l = 1; l <= n; ++l) { // 枚举j位置的颜色
                            if(l == k) {
                                if(f[i - 1][j][l] < inf) f[i][j][k] = min(f[i][j][k], f[i - 1][j][l] + cost[i][k - 1]);
                            } else {
                                if(f[i - 1][j - 1][l] < inf) f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][l] + cost[i][k - 1]);
                            }
                        }
                    }
                }
            }
        }
        int res = inf;
        for(int k = 1; k <= n; ++k) {
            res = min(res, f[m - 1][target][k]);
        }
        return res < inf ? res : -1;
    }
};