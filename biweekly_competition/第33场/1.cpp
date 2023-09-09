/*
* @Author: wilson_t
* @Date:   2020-08-23 12:55:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 12:57:53
*/
/*
给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。

示例 1：
输入：n = 987
输出："987"

示例 2：
输入：n = 1234
输出："1.234"

示例 3：
输入：n = 123456789
输出："123.456.789"

示例 4：
输入：n = 0
输出："0"
 
提示：
0 <= n < 2^31

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/thousand-separator
*/
class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        int len = s.size();
        string res = "";
        int nn = len;
        while(nn > 0) {
            res.push_back(s[len - nn]);
            --nn;
            if(nn != 0 && nn % 3 == 0) res.push_back('.');
        }
        return res;
    }
};