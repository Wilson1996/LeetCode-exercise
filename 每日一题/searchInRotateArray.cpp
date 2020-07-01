/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-27 09:12:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-27 10:13:48
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int binSearch(vector<int>& nums, int l, int r, int target)
    {
        if(l >= r)
            return -1;
        int mid = (l + r) / 2;
        if(nums[mid] == target)
            return mid;
        if(nums[l] == target)
            return l;
        if(nums[r - 1] == target)
            return r - 1;
        if(nums[l] <= nums[mid])
        {
            if(target >= nums[l] && target <= nums[mid])
                return binSearch(nums, l, mid, target);
            else
                return binSearch(nums, mid + 1, r, target);
        }
        else
        {
            if(target >= nums[mid] && target <= nums[r - 1])
                return binSearch(nums, mid + 1, r, target);
            else
                return binSearch(nums, l, mid, target);
        }
    }
    int search(vector<int>& nums, int target)
    {
        // //递归
        //    return binSearch(nums, 0, nums.size(), target);
        //迭代
        int len = nums.size();
        int l = 0, r = len, mid;
        while(l < r)
        {
            mid = (l + r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[l] <= nums[mid])
            {
                if(target >= nums[l] && target <= nums[mid]) r = mid;
                else l = mid + 1;
            }
            else
            {
                if(target >= nums[mid] && target <= nums[r - 1]) l = mid + 1;
                else r = mid;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {6, 7, 1, 2, 3, 4, 5};
    Solution soluter;
    cout << soluter.search(nums, 0) << endl;
    return 0;
}