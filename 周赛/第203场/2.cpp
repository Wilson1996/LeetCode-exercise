/*
* @Author: wilson_t
* @Date:   2020-08-23 13:17:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 13:19:54
*/
/*
有 3n 堆数目不一的硬币，你和你的朋友们打算按以下方式分硬币：
每一轮中，你将会选出 任意 3 堆硬币（不一定连续）。
Alice 将会取走硬币数量最多的那一堆。
你将会取走硬币数量第二多的那一堆。
Bob 将会取走最后一堆。
重复这个过程，直到没有更多硬币。
给你一个整数数组 piles ，其中 piles[i] 是第 i 堆中硬币的数目。
返回你可以获得的最大硬币数目。

提示：
3 <= piles.length <= 10^5
piles.length % 3 == 0
1 <= piles[i] <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-coins-you-can-get
*/
class Solution {
public:
    int maxCoins(vector<int>& p) {
        sort(p.begin(), p.end());
        int n = p.size();
        int res = 0;
        int l = 0;
        int r = n - 2;
        while(l < r) {
            res += p[r];
            l++;
            r -= 2;
        }
        return res;
    }
};