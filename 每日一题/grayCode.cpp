/*
* @Author: wilson_t
* @Date:   2020-10-06 22:33:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-30 14:14:53
*/
/*****************************************************************
* 题目[中等]：
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。即使有多个不同答案，你也只需要返回其中一种。
格雷编码序列必须以 0 开头。

示例 1:
输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2
对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。
00 - 0
10 - 2
11 - 3
01 - 1

示例 2:
输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
*****************************************************************/
#include <bits/stdc++.h>
#include "debug.h"
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int highest = 1;
        res.push_back(0);
        for(int i = 0; i < n; ++i) {
            highest = 1 << i;
            int len = res.size();
            for(int j = len - 1; j >= 0; --j) {
                res.push_back(highest + res[j]);
            }
        }
        return res;
    }
};


class GrayCode {
public:
    vector<string> getGray(int n) {
        vector<string> res;
        int highest = 1;
        res.emplace_back(string(n, '0'));
        for(int i = 0; i < n; ++i) {
            highest = 1 << i;
            int len = res.size();
            for(int j = len - 1; j >= 0; --j) {
                string nxt = res[j];
                nxt[n-1-i] = '1';
                res.emplace_back(nxt);
            }
        }
        return res;
    }
};

int main(int argc, char* argv[]) {
    GrayCode grayCode;
    vector<string> res = grayCode.getGray(4);

    Debug() << res << "\n";

    return 0;
}