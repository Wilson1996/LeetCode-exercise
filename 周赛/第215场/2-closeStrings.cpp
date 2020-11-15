/*
* @Author: wilson_t
* @Date:   2020-11-15 21:22:32
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-15 21:23:17
*/
/**
* 题目[中等]：
如果可以使用以下操作从一个字符串得到另一个字符串，则认为两个字符串 接近 ：
操作 1：交换任意两个 现有 字符。
例如，abcde -> aecdb
操作 2：将一个 现有 字符的每次出现转换为另一个 现有 字符，并对另一个字符执行相同的操作。
例如，aacabb -> bbcbaa（所有 a 转化为 b ，而所有的 b 转换为 a ）
你可以根据需要对任意一个字符串多次使用这两种操作。
给你两个字符串，word1 和 word2 。如果 word1 和 word2 接近 ，就返回 true ；否则，返回 false 。

示例 1：
输入：word1 = "abc", word2 = "bca"
输出：true
解释：2 次操作从 word1 获得 word2 。
执行操作 1："abc" -> "acb"
执行操作 1："acb" -> "bca"

示例 2：
输入：word1 = "a", word2 = "aa"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。

示例 3：
输入：word1 = "cabbba", word2 = "abbccc"
输出：true
解释：3 次操作从 word1 获得 word2 。
执行操作 1："cabbba" -> "caabbb"
执行操作 2："caabbb" -> "baaccc"
执行操作 2："baaccc" -> "abbccc"

示例 4：
输入：word1 = "cabbba", word2 = "aabbss"
输出：false
解释：不管执行多少次操作，都无法从 word1 得到 word2 ，反之亦然。

提示：
1 <= word1.length, word2.length <= 105
word1 和 word2 仅包含小写英文字母
 */
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        int cnt1[26] = {0}, cnt2[26] = {0};
        for(char c : word1) {
            cnt1[c - 'a']++;
        }
        for(char c : word2) {
            cnt2[c - 'a']++;
        }
        for(int i = 0; i < 26; ++i) {
            if((cnt1[i] == 0 && cnt2[i] != 0) || (cnt1[i] != 0 && cnt2[i] == 0)) return false;
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        for(int i = 0; i < 26; ++i) {
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
};