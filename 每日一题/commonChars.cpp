/*
* @Author: wilson_t
* @Date:   2020-10-14 09:04:07
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-14 09:05:00
*/
/**
* 题目[简单]：
给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。
例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。
你可以按任意顺序返回答案。
 
示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]

示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]

提示：
1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] 是小写字母

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-common-characters
*/
class Solution {
    int mp[105][26];
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        for(int i = 0; i < n; ++i) for(int j = 0; j < 26; ++j) mp[i][j] = 0;
        for(int i = 0; i < n; ++i) {
            for(char c : A[i]) mp[i][c - 'a']++;
        }
        vector<string> res;
        for(int j = 0; j < 26; ++j) {
            int cnt = INT_MAX;
            for(int i = 0; i < n; ++i) {
                cnt = min(cnt, mp[i][j]);
                if(cnt == 0) break;
            }
            for(int k = 0; k < cnt; ++k) {
                res.emplace_back(1, j + 'a');
            }
        }
        return res;
    }
};