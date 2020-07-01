/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-10 10:39:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-10 12:18:44
*/
/*********************************************************
给你一个整数数组 arr 。

现需要从数组中取三个下标 i、j 和 k ，其中 (0 <= i < j <= k < arr.length) 。

a 和 b 定义如下：

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
注意：^ 表示 按位异或 操作。

请返回能够令 a == b 成立的三元组 (i, j , k) 的数目。
*********************************************************/
class Solution
{
public:
    int countTriplets(vector<int>& arr)
    {
        int res = 0;
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 0; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                dp[i][j] = dp[i][j - 1] ^ arr[j - 1];
                for(int k = 0; k < i; ++k)
                {
                    if(dp[k][i] == dp[i][j]) ++res;
                }
            }
        }
        return res;
    }
};

/*
class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        temp = 0
        loc = collections.defaultdict(list)
        loc[0] = [-1]
        ans = 0
        for i in range(len(arr)):
            temp ^= arr[i]
            ans += sum(i - j - 1 for j in loc[temp])
            loc[temp].append(i)
        return ans
*/