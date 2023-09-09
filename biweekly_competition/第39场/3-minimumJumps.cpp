/*
* @Author: wilson_t
* @Date:   2020-11-15 21:03:41
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-15 21:04:54
*/
/**
* 题目[中等]：
有一只跳蚤的家在数轴上的位置 x 处。请你帮助它从位置 0 出发，到达它的家。
跳蚤跳跃的规则如下：
它可以 往前 跳恰好 a 个位置（即往右跳）。
它可以 往后 跳恰好 b 个位置（即往左跳）。
它不能 连续 往后跳 2 次。
它不能跳到任何 forbidden 数组中的位置。
跳蚤可以往前跳 超过 它的家的位置，但是它 不能跳到负整数 的位置。
给你一个整数数组 forbidden ，其中 forbidden[i] 是跳蚤不能跳到的位置，同时给你整数 a， b 和 x ，
请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 x 的可行方案，请你返回 -1 。

示例 1：
输入：forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
输出：3
解释：往前跳 3 次（0 -> 3 -> 6 -> 9），跳蚤就到家了。

示例 2：
输入：forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
输出：-1

示例 3：
输入：forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
输出：2
解释：往前跳一次（0 -> 16），然后往回跳一次（16 -> 7），跳蚤就到家了。

提示：
1 <= forbidden.length <= 1000
1 <= a, b, forbidden[i] <= 2000
0 <= x <= 2000
forbidden 中所有位置互不相同。
位置 x 不在 forbidden 中。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-jumps-to-reach-home
 */
using PII = pair<int, int>;
class Solution {
public:
    int minimumJumps(vector<int>& forbid, int a, int b, int x) {
        int mx = 2000 + 5;
        int dis[100005][2];
        memset(dis, 0x3f, sizeof(dis));
        dis[0][0] = 0;
        vector<int> vis(mx, false);
        for(int x : forbid) vis[x] = true;
        queue<PII> q;
        q.emplace(0, 0);
        vis[0] = true;
        while(!q.empty()) {
            int size = q.size();
            for(int _ = 0; _ < size; ++_) {
                auto [cur, flag] = q.front();
                q.pop();
                int nx = cur + a;
                if(nx <= 6001 && (nx > 2000 || !vis[nx]) && dis[nx][0] == 0x3f3f3f3f) {
                    dis[nx][0] = dis[cur][flag] + 1;
                    q.emplace(nx, 0);
                }
                if(flag == 0) {
                    nx = cur - b;
                    if(nx >= 0 && (nx > 2000 || !vis[nx]) && dis[nx][1] == 0x3f3f3f3f) {
                        dis[nx][1] = dis[cur][flag] + 1;
                        q.emplace(nx, 1);
                    }
                }
            }
        }
        if (dis[x][0] == 0x3f3f3f3f && dis[x][1] == 0x3f3f3f3f)
            return -1;
        return min(dis[x][0], dis[x][1]);
    }
};