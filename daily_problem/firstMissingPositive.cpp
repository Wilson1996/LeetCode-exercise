/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-27 09:07:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-27 10:33:02
*/
class Solution
{
public:
    //空间复杂度为O(n)
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        unordered_set<int> ms;
        int Max = 0;
        for(auto& x : nums)
        {
            ms.insert(x);
            Max = max(Max, x);
        }
        for(int i = 1; i < Max; ++i)
        {
            if(ms.find(i) == ms.end())
                return i;
        }
        return Max + 1;
    }
    //空间复杂度为O(1)的解法，置换
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
    //空间复杂度为O(1)的解法，原地哈希
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] <= 0) nums[i] = n + 1;
        }
        for(int i = 0; i < n; ++i)
        {
            int num = abs(nums[i]);
            if(num <= n)
            {
                nums[num - 1] = -abs(nums[num - 1]);
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};