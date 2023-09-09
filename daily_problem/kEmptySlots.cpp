/*
* @Author: wilson_t
* @Date:   2020-11-12 14:24:58
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-12 14:26:50
*/
/****************************************************************
* 题目[困难]：
N个灯泡排成一行，编号从 1 到 N 。最初，所有灯泡都关闭。每天只打开一个灯泡，直到 N 天后所有灯泡都打开。
给你一个长度为 N 的灯泡数组 blubs ，其中 bulls[i] = x 意味着在第 (i+1) 天，我们会把在位置 x 的灯泡打开，其中 i 从 0 开始，x 从 1 开始。
给你一个整数 K ，请你输出在第几天恰好有两个打开的灯泡，使得它们中间 正好 有 K 个灯泡且这些灯泡 全部是关闭的 。
如果不存在这种情况，返回 -1 。如果有多天都出现这种情况，请返回 最小的天数 。
 
示例 1：
输入：
bulbs: [1,3,2]
K: 1
输出：2
解释：
第一天 bulbs[0] = 1，打开第一个灯泡 [1,0,0]
第二天 bulbs[1] = 3，打开第三个灯泡 [1,0,1]
第三天 bulbs[2] = 2，打开第二个灯泡 [1,1,1]
返回2，因为在第二天，两个打开的灯泡之间恰好有一个关闭的灯泡。

示例 2：
输入：
bulbs: [1,2,3]
k: 1
输出：-1

提示：
1 <= N <= 20000
1 <= bulbs[i] <= N
bulbs 是一个由从 1 到 N 的数字构成的排列
0 <= K <= 20000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/k-empty-slots
****************************************************************/

class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int k) {
        int n = bulbs.size();
        set<int> st;
        for(int i = 0; i < n; ++i) {
            int& x = bulbs[i];
            auto [it, _] = st.insert(x);
            auto left = it;
            if(it != st.begin()) {
                --left;
                if(left != st.end() && (x - *left) == k + 1) return i + 1;
            }
            auto right = it;
            ++right;
            if(right != st.end() && (*right - x) == k + 1) return i + 1;
        }
        return -1;
    }
};