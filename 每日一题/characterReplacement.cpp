/*
* @Author: wilson_t
* @Date:   2021-02-02 11:09:13
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-02-02 11:10:41
*/
/*
给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。
在执行上述操作后，找到包含重复字母的最长子串的长度。
注意：字符串长度 和 k 不会超过 104。
 
示例 1：
输入：s = "ABAB", k = 2
输出：4
解释：用两个'A'替换为两个'B',反之亦然。

示例 2：
输入：s = "AABABBA", k = 1
输出：4
解释：
将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
子串 "BBBB" 有最长重复字母, 答案为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-repeating-character-replacement
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int cnt[26] = {0};
        int res = 0, mxCnt = 0;
        while(r < n) {
            if(r - l - mxCnt <= k) {
                cnt[s[r] - 'A']++;
                mxCnt = max(mxCnt, cnt[s[r] - 'A']);
                res = max(res, r - l);
                r++;
            } else {
                cnt[s[l] - 'A']--;
                l++;
            }
        }
        if(r - l - mxCnt <= k) {
            res = max(res, r - l);
        }
        return res;
    }
};