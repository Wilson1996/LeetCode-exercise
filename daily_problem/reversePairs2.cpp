/*
* @Author: wilson_t
* @Date:   2020-11-28 13:48:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-29 00:00:27
*/
/**
*题目[困难]：
给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
你需要返回给定数组中的重要翻转对的数量。

示例 1:
输入: [1,3,2,3,1]
输出: 2

示例 2:
输入: [2,4,3,5,1]
输出: 3

注意:
给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-pairs
 */

//方法一
using ll = long long;
class TreeArray {
    vector<int> cv;
    int cn;
public:
    TreeArray(int size) : cn(size), cv(size + 1, 0) {}

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= cn) {
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += cv[i];
            i -= lowbit(i);
        }
        return sum;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        set<int> st(nums.begin(), nums.end());
        map<ll, int> mp;
        int rank = 1;
        for(auto& x : st) {
            mp[(ll)x] = rank++;
        }
        int res = 0;
        TreeArray numArr(mp.size());
        for(int i = 0; i < n; ++i) {
            //离散化现有元素，二分查找需要的元素的位置。
            auto it = mp.lower_bound((ll)nums[i] * 2);
            if(it != mp.end()) {
                if((ll)nums[i] * 2 < it->first) {
                    res += (i - numArr.query(it->second - 1));
                } else {
                    res += (i - numArr.query(it->second));
                }
            }
            numArr.update(mp[nums[i]], 1);
        }
        return res;
    }
};


//方法二
using ll = long long;
class TreeArray {
    vector<int> cv;
    int cn;
public:
    TreeArray(int size) : cn(size), cv(size + 1, 0) {}

    int lowbit(int x) {
        return x & (-x);
    }

    void update(int i, int x) {
        while(i <= cn) {
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += cv[i];
            i -= lowbit(i);
        }
        return sum;
    }
};

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        set<ll> ms;
        //离散化所有需要的元素
        for(int x : nums) {
            ms.insert((ll)x);
            ms.insert((ll)x * 2);
        }
        unordered_map<ll, int> mp;
        int rank = 1;
        for(auto& x : ms) {
            mp[(ll)x] = rank++;
        }
        int res = 0;
        TreeArray treeArr(mp.size());
        for(int i = 0; i < n; ++i) {
            res += (i - treeArr.query(mp[(ll)nums[i] * 2]));
            treeArr.update(mp[nums[i]], 1);
        }
        return res;
    }
};