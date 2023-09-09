/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-24 11:10:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-10 20:53:42
*/
/*********************************************************
* 题目[困难]：
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int mergesort(vector<int>& nums, int l, int r) {
        if(r - l <= 1) return 0;
        int mid = (l + r) / 2, cnt = 0;
        cnt += mergesort(nums, l, mid);
        cnt += mergesort(nums, mid, r);
        cnt += merge(nums, l, mid, r);
        return cnt;
    }

    int merge(vector<int>& nums, int l, int mid, int r) {
        vector<int> front(nums.begin() + l, nums.begin() + mid);
        int i = 0, j = mid, n1 = mid - l, idx = l, cnt = 0;
        while(i < n1 || j < r) {
            if(i < n1 && j < r) {
                if(front[i] <= nums[j]) {
                    nums[idx++] = front[i++];
                } else {
                    cnt += (n1 - i);
                    nums[idx++] = nums[j++];
                }
            } else if(i < n1) {
                nums[idx++] = front[i++];
            } else {
                nums[idx++] = nums[j++];
            }
        }
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergesort(nums, 0, nums.size());
    }
};

//树状数组
class Solution2 {
    vector<int> cv;
    int n, cn;
public:
    int lowbit(int x){
        return x & (-x);
    }

    void update(int i, int x){
        while(i <= cn){
            cv[i] += x;
            i += lowbit(i);
        }
    }

    int query(int i){
        int sum = 0;
        while(i > 0){
            sum += cv[i];
            i -= lowbit(i); 
        }
        return sum;
    }

    int reversePairs(vector<int>& nums) {
        n = nums.size();
        set<int> ms(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int rank = 1;
        for(auto& x : ms){
            mp[x] = rank++;
        }
        cn = mp.size();
        cv = vector<int>(cn+1, 0);
        int res = 0;
        for(int i = n-1; i >= 0; --i){
            int rank = mp[nums[i]];
            update(rank, 1);
            res += query(rank-1);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = {7, 5, 6, 4, 4, 4, 10};//11
    Solution2 soluter;
    cout << soluter.reversePairs(nums) << endl;
    return 0;
}