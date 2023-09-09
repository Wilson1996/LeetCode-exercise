/*
* 题目[困难]：
给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。
第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR xi) ，
其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。
返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。

示例 1：
输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
输出：[3,3,7]
解释：
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.

示例 2：
输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
输出：[15,-1,5]
 
提示：
1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array
 */

struct Query {
    int x, m, i;
};

class Trie {
    Trie* child[2];
public:
    Trie() {
        child[0] = child[1] = nullptr;
    }

    void insert(int x) {
        Trie* it = this;
        for(int i = 30; i >= 0; --i) {
            int idx = (x & (1 << i)) ? 1 : 0;
            if(it->child[idx] == nullptr) it->child[idx] = new Trie();
            it = it->child[idx];
        }
    }

    int getMax(int x) {
        Trie* it = this;
        int res = 0;
        for(int i = 30; i >= 0; --i) {
            int idx = (x & (1 << i)) ? 1 : 0;
            if(it->child[1 - idx] != nullptr) {
                it = it->child[1 - idx];
                res |= ((1 - idx) << i);
            } else {
                it = it->child[idx];
                res |= (idx << i);
            }
        }
        return res;
    }

    bool isEmpty() {
        Trie* it = this;
        return child[0] == nullptr && child[1] == nullptr;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<Query> qs(m);
        vector<int> res(m);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < m; ++i) {
            qs[i].x = queries[i][0];
            qs[i].m = queries[i][1];
            qs[i].i = i;
        }
        sort(qs.begin(), qs.end(), [&](const Query & a, const Query & b) {
            return a.m < b.m;
        });

        Trie trie;
        int idx = 0;
        for(int i = 0; i < m; ++i) {
            while(idx < n && nums[idx] <= qs[i].m) {
                trie.insert(nums[idx]);
                ++idx;
            }
            if(trie.isEmpty()) res[qs[i].i] = -1;
            else res[qs[i].i] = trie.getMax(qs[i].x) ^ qs[i].x;
        }

        return res;
    }
};