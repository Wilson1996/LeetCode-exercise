/*
* @Author: wilson_t
* @Date:   2020-10-22 09:57:51
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-22 10:00:00
*/
/*********************************************************
* 题目[中等]：
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，
同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。

示例 1：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
 
提示：
S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/partition-labels
*********************************************************/
//双指针
class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int length = S.size();
        for (int i = 0; i < length; i++) {
            last[S[i] - 'a'] = i;
        }
        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.size(), count = 0;
        vector<int> res;
        int cnt[26] = {0};
        auto check = [ = ](int cnt[], int cnt_tmp[]) {
            for(int i = 0; i < 26; ++i) {
                if(cnt_tmp[i] != 0 && cnt_tmp[i] != cnt[i]) return false;
            }
            return true;
        };
        for(char c : S) cnt[c - 'a']++;
        for(int i = 0; i < n; ) {
            int cnt_tmp[26] = {0};
            while(i < n) {
                cnt_tmp[S[i] - 'a']++;
                ++i;
                ++count;
                if(check(cnt, cnt_tmp)) {
                    for(int j = 0; j < 26; ++j) {
                        cnt[j] -= cnt_tmp[j];
                    }
                    res.emplace_back(count);
                    count = 0;
                    break;
                }
            }
        }
        return res;
    }
};
