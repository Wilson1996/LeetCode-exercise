/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-13 20:59:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-14 00:10:05
*/
/*
给你一个整数数组 arr 和一个整数值 target 。
请你在 arr 中找 两个互不重叠的子数组 且它们的和都等于 target 。
可能会有多种方案，请你返回满足要求的两个子数组长度和的 最小值 。
请返回满足要求的最小长度和，如果无法找到这样的两个子数组，请返回 -1 。

示例 1：
输入：arr = [3,2,2,4,3], target = 3
输出：2
解释：只有两个子数组和为 3 （[3] 和 [3]）。它们的长度和为 2 。
*/
class Solution
{
public:
    // int minSumOfLengths(vector<int>& arr, int target)
    // {
    //     int n = arr.size();
    //     vector<int> pre(n, 0);
    //     pre[0] = arr[0];
    //     for(int i = 1; i < n; ++i) pre[i] = arr[i] + pre[i - 1];
    //     int res = 1e9;
    //     for(int i = 1; i < n; ++i)
    //     {
    //         int p1 = 0, p2 = 0;
    //         bool found1 = false;
    //         int tmpRes;
    //         while(p2 < i)
    //         {
    //             int tmp = pre[p2] - pre[p1] + arr[p1];
    //             if(tmp == target) {found1 = true; break;}
    //             if(tmp < target) ++p2;
    //             else ++p1;
    //         }
    //         if(found1)
    //         {
    //             tmpRes = p2 - p1 + 1;
    //             p1 = p2 = i;
    //             bool found2 = false;
    //             while(p2 < n)
    //             {
    //                 int tmp = pre[p2] - pre[p1] + arr[p1];
    //                 if(tmp == target) {found2 = true; break;}
    //                 if(tmp < target) ++p2;
    //                 else ++p1;
    //             }
    //             if(found2)
    //             {
    //                 tmpRes += p2 - p1 + 1;
    //                 res = min(tmpRes, res);
    //             }
    //         }
    //     }
    //     return res == 1e9 ? -1 : res;
    // }
    int minSumOfLengths(vector<int>& arr, int target)
    {
        int n = arr.size();
        vector<int> pre(n, 0);
        pre[0] = arr[0];
        for(int i = 1; i < n; ++i) pre[i] = arr[i] + pre[i - 1];
        int res = 1e9;
        int left1 = 0, right1 = 1, left2 = n - 1, right2 = n;
        int res1 = 1e9;, res2 = 1e9;
        bool found1 = false, found2 = false;
        while(right1 < left2)
        {
            int tmp1 = pre[right1] - pre[left1];
            if(tmp1 == target) {found1 = true; res1 = min(res1, right1 - left1); ++left1;}
            else if(tmp1 < target) ++right1;
            else ++left1;
            int tmp2 = pre[right2] - pre[left2];
            if(tmp2 == target) {found2 = true; res2 = min(res2, right2 - left2); --right2;}
            else if(tmp2 < target) --left2;
            else --right2;
        }
        if(found1 && found2) return res1 + res2;
        // return res == 1e9 ? -1 : res;
    }
};

class Solution
{
    unordered_map<int, int> mp;
    int f[100005];
public:
    int minSumOfLengths(vector<int>& arr, int target)
    {
        int sum = 0;
        mp[0] = 0;
        int n = arr.size(), ans = 0x3f3f3f3f;
        memset(f, 0x3f, sizeof(f));
        for (int i = 1; i <= n; ++i)
        {
            sum += arr[i - 1];
            int gp = sum - target;
            f[i] = f[i - 1];
            if (mp.count(gp))
            {
                int pos = mp[gp];
                f[i] = min(f[i], i - pos);
                ans = min(ans, i - pos + f[pos]);
            }
            mp[sum] = i;
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};