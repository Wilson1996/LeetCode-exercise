/*
* @Author: wilson_t
* @Date:   2020-11-14 14:01:37
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-14 14:04:07
*/
/*
* 题目[中等]：
我们都知道安卓有个手势解锁的界面，是一个 3 x 3 的点所绘制出来的网格。用户可以设置一个 “解锁模式” ，
通过连接特定序列中的点，形成一系列彼此连接的线段，每个线段的端点都是序列中两个连续的点。如果满足以下两个条件，
则 k 点序列是有效的解锁模式：
解锁模式中的所有点 互不相同 。
假如模式中两个连续点的线段需要经过其他点，那么要经过的点必须事先出现在序列中（已经经过），不能跨过任何还未被经过的点。
两个解锁模式 不同 需满足：经过的点不同或者经过点的顺序不同。
 
示例 1：
输入：m = 1, n = 1
输出：9

示例 2：
输入：m = 1, n = 2
输出：65

提示：
1 <= m, n <= 9

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/android-unlock-patterns
*/
class Solution {
    int m, n;
    bool vis[3][3];
public:
    int dfs(int x, int y, int cnt) {
        int res = 0;
        if(cnt >= m && cnt <= n) {
            ++res;
        } else if(cnt > n || cnt > 9) return 0;
        vis[x][y] = true;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(vis[i][j]) continue;
                if(i == x && j == 2 - y) {
                    if(!vis[i][(j + y) / 2]) continue;
                }
                if(j == y && i == 2 - x) {
                    if(!vis[(i + x) / 2][j]) continue;
                }
                if(i == 2 - x && j == 2 - y && !vis[(i + x) / 2][(j + y) / 2]) continue;
                res += dfs(i, j, cnt + 1);
            }
        }
        vis[x][y] = false;
        return res;
    }
    int numberOfPatterns(int _m, int _n) {
        m = _m, n = _n;
        memset(vis, 0, sizeof(vis));
        int res = 0;
        //根据对称性优化
        res += dfs(0, 0, 1) * 4;
        res += dfs(0, 1, 1) * 4;
        res += dfs(1, 1, 1);
        return res;
    }
};