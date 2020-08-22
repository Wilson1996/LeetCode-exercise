/*
* @Author: wilson_t
* @Date:   2020-08-22 10:58:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-22 11:09:24
*/
/*********************************************************
* 题目[困难]：
你有 4 张写有 1 到 9 数字的牌。你需要判断是否能通过 *，/，+，-，(，) 的运算得到 24。

示例 1:
输入: [4, 1, 8, 7]
输出: True
解释: (8-4) * (7-1) = 24

示例 2:
输入: [1, 2, 1, 2]
输出: False

注意:
除法运算符 / 表示实数除法，而不是整数除法。例如 4 / (1 - 2/3) = 12 。
每个运算符对两个数进行运算。特别是我们不能用 - 作为一元运算符。例如，[1, 1, 1, 1] 作为输入时，表达式 -1 - 1 - 1 - 1 是不允许的。
你不能将数字连接在一起。例如，输入为 [1, 2, 1, 2] 时，不能写成 12 + 12 。
*********************************************************/
class Solution {
    bool found = false;
    char OP[4] = {'+', '-', '*', '/'};
public:
    double oper(double x, double y, char sign) {
        switch(sign) {
            case '+': return x + y;
            case '-': return x - y;
            case '*': return x * y;
            case '/': return x / y;
        }
        return 0;
    }
    bool judge(vector<double>& nums) {
        int n = nums.size();
        if(n == 1) {
            return fabs(nums[0] - 24) < 1e-6;
        }
        vector<double> nxt(n - 1);
        for(int i = 0; i < n - 1; ++i) {
            int j = 0;
            for(; j < i; ++j) {
                nxt[j] = nums[j];
            }
            int idx = j;
            for(j = i + 1; j < n - 1; ++j) {
                nxt[j] = nums[j + 1];
            }
            for(int k = 0; k < 4; ++k) {
                nxt[idx] = oper(nums[i], nums[i + 1], OP[k]);
                if(judge(nxt)) return true;
            }
        }
        return false;
    }
    void dfs(vector<double>& nums, int idx) {
        if(idx == 4) {
            found = judge(nums);
            return;
        }
        if(!found) {
            dfs(nums, idx + 1);
            for(int i = idx + 1; i < 4; ++i) {
                if(nums[i] == nums[idx]) continue;
                swap(nums[idx], nums[i]);
                dfs(nums, idx + 1);
                swap(nums[idx], nums[i]);
            }
        }
    }
    bool judgePoint24(vector<int>& nums) {
        found = false;
        vector<double> dnums(4);
        for(int i = 0; i < 4; ++i) {
            dnums[i] = (double)nums[i];
        }
        dfs(dnums, 0);
        return found;
    }
};