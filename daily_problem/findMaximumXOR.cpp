/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-10 01:10:09
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-11 01:03:41
*/
/*********************************************************
* 题目[中等]：
给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231 。
找到 ai 和aj 最大的异或 (XOR) 运算结果，其中0 ≤ i,  j < n 。
你能在O(n)的时间解决这个问题吗？

示例:
输入: [3, 10, 5, 25, 2, 8]
输出: 28
解释: 最大的结果是 5 ^ 25 = 28.
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

struct Int2
{
    int d[2];
    Int2() {d[0] = d[1] = -1;}
    int& operator[](int i) {return d[i];}
};

class Solution
{
    vector<Int2> trie;
    long long n;
    int res;
public:
    void print(int p)
    {
        if(p == -1) return;
        cout << p << ", ";
        print(trie[p][0]);
        
        print(trie[p][1]);
    }
    void search(int p1, int p2, int depth)
    {
        if(depth == 32)
        {
            cout << "p1: " << p1 << " p2: " << p2 << endl;
            res = max(p1 ^ p2, res);
            return;
        };
        if(trie[p2][1] != -1 && trie[p1][0] != -1)
        {
            search(trie[p1][0], trie[p2][1], depth + 1);
        }
        if(p1 != p2 && trie[p1][1] != -1 && trie[p2][0] != -1)
        {
            search(trie[p1][1], trie[p2][0], depth + 1);
        }
        if(!((trie[p2][1] != -1 && trie[p1][0] != -1) || (trie[p1][1] != -1 && trie[p2][0] != -1)))
        {
            if(trie[p1][0] != -1)
            {
                search(trie[p1][0], trie[p2][0], depth + 1);
            }
            else
            {
                search(trie[p1][1], trie[p2][1], depth + 1);
            }
        }
    }
    int findMaximumXOR(vector<int>& nums)
    {
        res = 0;
        n = 1;
        trie.resize(nums.size() * (1ll << 20));
        for(auto& x : nums)
        {
            int p = 0, tmp;
            for(int i = 31; i >= 0; --i)
            {
                if(trie.size() < p) trie.resize(trie.size() * 2ll);
                tmp = (x >> i) & 1;
                if(trie[p][tmp] == -1)
                {
                    trie[p][tmp] = n++;
                }
                if(i == 0) trie[p][tmp] = x;	//最终的地方存节点的值
                p = trie[p][tmp];
            }
            // trie[p][0] = trie[p][1] = x;	//最终的地方存节点的值
        }
        // for(int i = 0; i < n; ++i)
        // {
        // 	cout << i << ": " << trie[i][0] << ", " << trie[i][1] << endl;
        // }
        // print(0);
        search(0, 0, 0);
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << soluter.findMaximumXOR(nums) << endl;
    return 0;
}