/*
* @Author: wilson_t
* @Date:   2021-06-06 17:59:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-13 10:17:18
*/
/*
给你一个二进制字符串s。你可以按任意顺序执行以下两种操作任意次：
类型 1 ：删除 字符串s的第一个字符并将它 添加到字符串结尾。
类型 2 ：选择 字符串s中任意一个字符并将该字符反转，也就是如果值为'0'，则反转得到'1'，反之亦然。
请你返回使 s变成 交替 字符串的前提下，类型 2的 最少操作次数。
我们称一个字符串是 交替的，需要满足任意相邻字符都不同。
比方说，字符串"010" 和"1010"都是交替的，但是字符串"0100"不是。

示例 1：
输入：s = "111000"
输出：2
解释：执行第一种操作两次，得到 s = "100011" 。
然后对第三个和第六个字符执行第二种操作，得到 s = "101010" 。

示例 2：
输入：s = "010"
输出：0
解释：字符串已经是交替的。

示例 3：
输入：s = "1110"
输出：1
解释：对第二个字符执行第二种操作，得到 s = "1010" 。

提示：
1 <= s.length <= 105
s[i]要么是'0'，要么是'1'。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating
 */
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss = s + s;
        int even = 0, odd = 0;  //1的个数
        for(int i = 0; i < n; ++i) {
            if(ss[i] == '1') {
                if(i & 1) odd++;
                else even++;
            }
        }

        int res = min(even + n / 2 - odd, odd + (n + 1) / 2 - even);
        int m = 2 * n;
        for(int i = n; i < m; ++i) {
            swap(even, odd);
            if(ss[i] == '1') {
                if((n - 1) & 1) odd++;
                else even++;
            }
            if(ss[i - n] == '1') {
                odd--;
            }

            res = min(res, min(even + n / 2 - odd, odd + (n + 1) / 2 - even));
        }
        return res;
    }
};