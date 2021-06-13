/*
* @Author: wilson_t
* @Date:   2021-06-09 11:10:00
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-09 11:12:24
*/
/*
集团里有 n 名员工，他们可以完成各种各样的工作创造利润。

第i种工作会产生profit[i]的利润，它要求group[i]名成员共同参与。如果成员参与了其中一项工作，就不能参与另一项工作。
工作的任何至少产生minProfit 利润的子集称为 盈利计划 。并且工作的成员总数最多为 n 。
有多少种计划可以选择？因为答案很大，所以 返回结果模10^9 + 7的值。

示例 1：
输入：n = 5, minProfit = 3, group = [2,2], profit = [2,3]
输出：2
解释：至少产生 3 的利润，该集团可以完成工作 0 和工作 1 ，或仅完成工作 1 。
总的来说，有两种计划。

示例 2：
输入：n = 10, minProfit = 5, group = [2,3,5], profit = [6,7,8]
输出：7
解释：至少产生 5 的利润，只要完成其中一种工作就行，所以该集团可以完成任何工作。
有 7 种可能的计划：(0)，(1)，(2)，(0,1)，(0,2)，(1,2)，以及 (0,1,2) 。

提示：
1 <= n <= 100
0 <= minProfit <= 100
1 <= group.length <= 100
1 <= group[i] <= 100
profit.length == group.length
0 <= profit[i] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/profitable-schemes
 */
using ll = long long;
const int mod = 1'000'000'007;
ll f[105][105][105]; //f[i][j][k]: 前i个工作，剩i个人时，最小利润要求为k时的方案数

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        memset(f, 0, sizeof(f));
        for(int person = 0; person <= n; ++person) {
            f[0][person][0] = 1;
            if(person >= group[0]) f[0][person][0]++;
            for(int minP = 1; minP <= minProfit; ++minP) {
                if(profit[0] >= minP && group[0] <= person) f[0][person][minP] = 1;
            }
        }
        for(int job = 1; job < m; ++job) {
            for(int person = 0; person <= n; ++person) {
                for(int minP = 0; minP <= minProfit; ++minP) {
                    f[job][person][minP] = f[job - 1][person][minP];
                    if(person >= group[job]) {
                        f[job][person][minP] += f[job - 1][person - group[job]][max(0, minP - profit[job])];
                    }
                    f[job][person][minP] %= mod;
                }
            }
        }
        return f[m - 1][n][minProfit] % mod;
    }
};