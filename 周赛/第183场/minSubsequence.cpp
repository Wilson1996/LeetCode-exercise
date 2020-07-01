/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-05 11:15:13
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-05 11:18:48
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int cmp(int a, int b)
{
    return a > b;
}
class Solution
{
public:
    static vector<int> minSubsequence(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), cmp);
        vector<int> result;
        for(auto it = nums.begin(); it != nums.end(); ++it)
        {
            if(accumulate(nums.begin(), it, 0) <= accumulate(it, nums.end(), 0))
                result.push_back(*it);
            else
                break;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {6};
    vector<int> result = Solution::minSubsequence(nums);
    for(int x: result)
        cout << x << ", ";
    cout << endl;
    return 0;
}