/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-14 09:38:35
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-14 10:31:20
*/
class Solution
{
public:
    vector<int> runningSum(vector<int>& nums)
    {
    	int n = nums.size();
    	vector<int> res(n);
    	res[0] = nums[0];
    	for (int i = 1; i < n; ++i)
    	{
    		res[i] = nums[i] + res[i - 1];
    	}
    	return res;
    }
};