/*
* @Author: wilson_t
* @Date:   2020-12-02 10:06:30
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-02 10:59:14
*/
/**
* 题目[困难]：
给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。
现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。
求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。
说明: 请尽可能地优化你算法的时间和空间复杂度。

示例 1:
输入:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
输出:
[9, 8, 6, 5, 3]

示例 2:
输入:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
输出:
[6, 7, 6, 0, 4]

示例 3:
输入:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
输出:
[9, 8, 9]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/create-maximum-number
*/


// using PII = pair<int, int>;
// class Solution {
// public:
//     vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//         int m = nums1.size(), n = nums2.size();
//         vector<int> res;
//         priority_queue<PII, vector<PII>, less<PII>> pq;
//         for(int i = 0; i < m; ++i) {
//             pq.emplace(nums1[i], i);
//         }
//         for(int i = 0; i < n; ++i) {
//             pq.emplace(nums2[i], i+m);
//         }
//         int ptr1 = 0, ptr2 = m;
//         for(int i = 0; i < k; ++i) {
//             int remain = k - i;
//             vector<PII> cache;
//             while(!pq.empty()) {
//                 PII cur = pq.top();
//                 pq.pop();
//                 if(cur.second >= ptr1 && cur.second < m && cur.second <= (2*m-ptr2+n-remain)) {
//                     res.emplace_back(cur.first);
//                     ptr1 = cur.second+1;
//                     break;
//                 } else if(cur.second >= ptr2 && cur.second < (m+n) && cur.second <= (2*m-ptr1+n-remain)) {
//                     res.emplace_back(cur.first);
//                     ptr2 = cur.second+1;
//                     break;
//                 } else {
//                     cache.emplace_back(cur);
//                 }
//             }
//             for(PII& p : cache) {
//                 pq.emplace(p);
//             }
//         }

//         return res;
//     }
// };
//
//

class Solution {
public:
    vector<int> getMaxSeq(vector<int>& nums, int k) {
        int n = nums.size(), remain = n - k;
        vector<int> res;
        for(int i = 0; i < n; ++i) {
            while(!res.empty() && nums[i] > res.back() && remain > 0) {
                res.pop_back();
                --remain;
            }
            if (res.size() < k) {
                res.push_back(nums[i]);
            } else {
                remain--;
            }
        }
        return res;
    }

    //// sequence 不是有序的，所以不能用归并排序的merge
    // vector<int> merge(vector<int>&& a, vector<int>&& b) {
    //     int m = a.size(), n = b.size(), i = 0, j = 0, x, y;
    //     vector<int> res;
    //     while(i < m || j < n) {
    //         x = (i < m) ? a[i] : -1;
    //         y = (j < n) ? b[j] : -1;
    //         if(x >= y) {
    //             res.emplace_back(x);
    //             ++i;
    //         } else {
    //             res.emplace_back(y);
    //             ++j;
    //         }
    //     }
    //     return res;
    // }

    vector<int> merge(vector<int>&& a, vector<int>&& b) {
        int x = a.size(), y = b.size();
        if (x == 0) {
            return b;
        }
        if (y == 0) {
            return a;
        }
        int mergeLength = x + y;
        vector<int> merged(mergeLength);
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(a, index1, b, index2) > 0) {
                merged[i] = a[index1++];
            } else {
                merged[i] = b[index2++];
            }
        }
        return merged;
    }

    vector<int>& MAX(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            if(a[i] == b[i]) continue;
            else if(a[i] > b[i]) return a;
            else return b;
        }
        return a;
    }

    int compare(vector<int>& a, int index1, vector<int>& b, int index2) {
        int x = a.size(), y = b.size();
        while (index1 < x && index2 < y) {
            int difference = a[index1] - b[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        vector<int> res(k, -1);
        for(int i = 0; i <= k; ++i) {
            if(m < i || n < k - i) continue;
            vector<int> now = merge(getMaxSeq(nums1, i), getMaxSeq(nums2, k - i));
            res = MAX(res, now);
        }
        return res;
    }
};
