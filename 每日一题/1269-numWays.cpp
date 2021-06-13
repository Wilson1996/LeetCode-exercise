/*
* @Author: wilson_t
* @Date:   2021-05-13 14:30:48
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-05-13 14:52:19
*/
/*
有一个长度为 arrLen 的数组，开始有一个指针在索引 0 处。
每一步操作中，你可以将指针向左或向右移动 1 步，或者停在原地（指针不能被移动到数组范围外）。
给你两个整数 steps 和 arrLen ，请你计算并返回：在恰好执行 steps 次操作以后，指针仍然指向索引 0 处的方案数。
由于答案可能会很大，请返回方案数 模 10^9 + 7 后的结果。

示例 1：
输入：steps = 3, arrLen = 2
输出：4
解释：3 步后，总共有 4 种不同的方法可以停在索引 0 处。
向右，向左，不动
不动，向右，向左
向右，不动，向左
不动，不动，不动

示例  2：
输入：steps = 2, arrLen = 4
输出：2
解释：2 步后，总共有 2 种不同的方法可以停在索引 0 处。
向右，向左
不动，不动

示例 3：
输入：steps = 4, arrLen = 2
输出：8
 
提示：
1 <= steps <= 500
1 <= arrLen <= 10^6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps
 */
const int mod = 1e9 + 7;
using ll = long long;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        //f[i][j]: 前i步之后所在位置j的方案数
        int most = min(steps + 1, arrLen);
        vector<vector<ll>> f(steps + 1, vector<ll>(most + 1, 0));
        f[0][0] = f[0][1] = 1;
        for(int i = 1; i < steps; ++i) {
            for(int j = 0; j < most; ++j) {
                f[i][j] += f[i - 1][j]; //不动
                if(j > 0) f[i][j] += f[i - 1][j - 1]; //向右
                if(j < most - 1) f[i][j] += f[i - 1][j + 1]; //向左
                f[i][j] %= mod;
            }
        }
        return f[steps - 1][0] % mod;
    }
};


//利用滚动数组优化
const int mod = 1e9 + 7;
using ll = long long;
class Solution {
public:
    int numWays(int steps, int arrLen) {
        //f[i][j]: 前i步之后所在位置j的方案数
        int most = min(steps + 1, arrLen);
        vector<ll> f(most + 1, 0), next(most + 1, 0);
        f[0] = f[1] = 1;
        for(int i = 1; i < steps; ++i) {
            for(int j = 0; j < most; ++j) {
                next[j] = 0;
                next[j] += f[j];
                if(j > 0) next[j] += f[j - 1];
                if(j < most - 1) next[j] += f[j + 1];
                next[j] %= mod;
            }
            f.swap(next);
        }
        return f[0] % mod;
    }
};

//加速
const int mod = 1e9 + 7;
using ll = long long;
vector<int> f(505), nxt(505);
class Solution {
public:
    int numWays(int steps, int arrLen) {
        //f[i][j]: 前i步之后所在位置j的方案数
        int most = min(steps + 1, arrLen);
        f.assign(most + 1, 0);
        f[0] = f[1] = 1;
        for(int i = 1; i < steps; ++i) {
            for(int j = 0; j < most; ++j) {
                nxt[j] = 0;
                nxt[j] += f[j];
                if(j > 0) (nxt[j] += f[j - 1]) %= mod;
                if(j < most - 1) (nxt[j] += f[j + 1]) %= mod;
            }
            f.swap(nxt);
        }
        return f[0] % mod;
    }
};