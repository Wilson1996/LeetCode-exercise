/*
* @Author: wilson_t
* @Date:   2020-12-04 10:37:02
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-04 10:38:22
*/
/**
* 题目[中等]：
给你一个按升序排序的整数数组 num（可能包含重复数字），请你将它们分割成一个或多个子序列，其中每个子序列都由连续整数组成且长度至少为 3 。
如果可以完成上述分割，则返回 true ；否则，返回 false 。
 
示例 1：
输入: [1,2,3,3,4,5]
输出: True
解释:
你可以分割出这样两个连续子序列 :
1, 2, 3
3, 4, 5
 
示例 2：
输入: [1,2,3,3,4,4,5,5]
输出: True
解释:
你可以分割出这样两个连续子序列 :
1, 2, 3, 4, 5
3, 4, 5
 
示例 3：
输入: [1,2,3,4,4,5]
输出: False

提示：
输入的数组长度范围为 [1, 10000]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences
 */
using PII = pair<int, int>;
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(int x : nums) {
            if(pq.empty()) {
                pq.emplace(x, 1);
            } else {
                vector<PII> cache;
                while(!pq.empty()) {
                    PII cur = pq.top();
                    pq.pop();
                    if(cur.first + 1 < x) {
                        if(cur.second < 3) return false;
                    } else if(cur.first + 1 == x) {
                        pq.emplace(x, cur.second + 1);
                        break;
                    } else {
                        cache.emplace_back(cur);
                    }
                }
                if(pq.empty()) {
                    pq.emplace(x, 1);
                }
                for(PII& p : cache) {
                    pq.emplace(p);
                }
            }
        }
        while(!pq.empty()) {
            const PII& p = pq.top();
            // printf("(%d,%d) ", p.first, p.second);
            if(p.second < 3) return false;
            pq.pop();
        }
        return true;
    }
};

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> cnt, subs;
        for (int e : nums) ++cnt[e];
        for (int e : nums)
            if (!cnt[e]) continue;
            else if (subs[e - 1]) {
                --cnt[e];
                --subs[e - 1];
                ++subs[e];
            } else if (cnt[e + 1] && cnt[e + 2]) {
                --cnt[e];
                --cnt[e + 1];
                --cnt[e + 2];
                ++subs[e + 2];
            } else return false;
        return true;
    }
};