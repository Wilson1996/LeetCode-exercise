/*
* @Author: wilson_t
* @Date:   2021-07-03 20:24:44
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-07-10 13:14:06
*/

// lower_bound: 第一个大于等于target的值
int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(nums[mid] < target) l = mid + 1;
        else r = mid;
    }
    // l>=n时 不存在
    return l;
}

// upper_bound: 第一个大于target的值
int upper_bound(vector<int>& nums, int target) {
    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r) / 2;
        if(nums[mid] <= target) l = mid + 1;
        else r = mid;
    }
    // l>=n时 不存在
    return l;
}

// upper: 等于target的最后一个，或者没有target时返回小于target的最大值
int upper_bound(vector<int>& nums, int target) {
    int l = -1, r = n - 1;
    while(l < r) {
        int mid = (l + r + 1) / 2;
        if(nums[mid] <= target) l = mid;
        else r = mid - 1;
    }
    // l<0时 不存在
    return l;
}