/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-03 10:49:25
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-03 12:12:50
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    static int longestSubarray(vector<int>& nums, int limit)
    {
        int l = 0, r = 0;
        int res = 0;
        for(int r = 0; r < nums.size(); ++r)
        {
            int j = 0;
            for(j = r - 1; j >= l; --j)
            {
                if(abs(nums[r] - nums[j]) > limit)
                {
                    break;
                }
            }
            l = j + 1;
            if(r - l + 1 > res)	res = r - l + 1;
        }
        return res;
    }
};

class Solution2
{
public:
    static int longestSubarray(vector<int>& nums, int limit)
    {
        int n = nums.size(), ans = 0;
        multiset<int> ms;
        for(int L = 0, R = 0; L < n; L += 1)
        {
            while(R < n)
            {
                ms.insert(nums[R]);
                if(*ms.rbegin() - *ms.begin() > limit)
                {
                    ms.erase(ms.find(nums[R]));
                    break;
                }
                R += 1;
            }
            ans = max(R - L, ans);
            ms.erase(ms.find(nums[L]));
        }
        return ans;
    }
};

int main(int argc, char* argv[])
{
	vector<int> nums = {10,1,2,4,7,2};
	// vector<int> nums = {8,2,4,7};
	cout << Solution2::longestSubarray(nums, 4) << endl;
	return 0;
}