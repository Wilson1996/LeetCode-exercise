/*
* @Author: wilson_t
* @Date:   2020-08-23 13:17:44
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-24 22:59:49
*/
/*********************************************************
* 题目[困难]：
几块石子 排成一行 ，每块石子都有一个关联值，关联值为整数，由数组 stoneValue 给出。
游戏中的每一轮：Alice 会将这行石子分成两个 非空行（即，左侧行和右侧行）；Bob 负责计算每一行的值，
即此行中所有石子的值的总和。Bob 会丢弃值最大的行，Alice 的得分为剩下那行的值（每轮累加）。
如果两行的值相等，Bob 让 Alice 决定丢弃哪一行。下一轮从剩下的那一行开始。
只 剩下一块石子 时，游戏结束。Alice 的分数最初为 0 。
返回 Alice 能够获得的最大分数 。

示例 1：
输入：stoneValue = [6,2,3,4,5,5]
输出：18
解释：在第一轮中，Alice 将行划分为 [6，2，3]，[4，5，5] 。左行的值是 11 ，右行的值是 14 。Bob 丢弃了右行，Alice 的分数现在是 11 。
在第二轮中，Alice 将行分成 [6]，[2，3] 。这一次 Bob 扔掉了左行，Alice 的分数变成了 16（11 + 5）。
最后一轮 Alice 只能将行分成 [2]，[3] 。Bob 扔掉右行，Alice 的分数现在是 18（16 + 2）。游戏结束，因为这行只剩下一块石头了。

示例 2：
输入：stoneValue = [7,7,7,7,7,7,7]
输出：28

示例 3：
输入：stoneValue = [4]
输出：0
 
提示：
1 <= stoneValue.length <= 500
1 <= stoneValue[i] <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/stone-game-v
*********************************************************/
class Solution {
    int f[505][505];
    int pre[505];
public:
    int dfs(vector<int>& sv, int l, int r) {
        if(l >= r - 1) return 0;
        if(f[l][r] != -1) return f[l][r];

        int res = 0, sumL, sumR;
        for(int mid = l + 1; mid < r; ++mid) {
            sumL = pre[mid] - pre[l];
            sumR = pre[r] - pre[mid];
            if(sumL > sumR) {
                res = max(res, sumR + dfs(sv, mid, r));
            } else if(sumL < sumR) {
                res = max(res, sumL + dfs(sv, l, mid));
            } else {
                res = max(res, max(dfs(sv, l, mid), dfs(sv, mid, r)) + sumL);
            }
        }
        // printf("l=%d  r=%d  L=%d  R=%d  res=%d \n", l, r, sumL, sumR, res);
        return f[l][r] = res;
    }
    int stoneGameV(vector<int>& sv) {
        int n = sv.size();
        for(int i = 0; i < n + 1; ++i) for(int j = 0; j < n + 1; ++j) f[i][j] = -1;
        memset(pre, 0, sizeof(int) * (n + 1));
        for(int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + sv[i];
        }
        return dfs(sv, 0, n);
    }
};