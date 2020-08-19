/*
* @Author: wilson_t
* @Date:   2020-08-19 10:37:47
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-19 11:57:43
*/
#include <bits/stdc++.h>
using namespace std;

/*
* 方法一：中心扩展
* 方法二：Manacher算法
*/
class Solution {
    int res;
public:
    //中心扩展
    void expand(string& nums, int center) {
        int n = nums.size();
        ++res;
        //奇数
        int l = center - 1, r = center + 1;
        while(l >= 0 && r < n && nums[l] == nums[r]) {
            --l;
            ++r;
            ++res;
        }
        //偶数
        l = center;
        r = center + 1;
        while(l >= 0 && r < n && nums[l] == nums[r]) {
            --l;
            ++r;
            ++res;
        }
    }

    int countSubstrings(string s) {
        int n = s.size();
        if(n <= 1) return n;
        res = 0;
        for(int i = 0; i < n; ++i) {
            expand(s, i);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    cout << solution.countSubstrings("aaaaa") << endl;
    return 0;
}