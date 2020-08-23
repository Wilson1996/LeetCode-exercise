/*
* @Author: wilson_t
* @Date:   2020-08-23 13:17:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-23 13:19:02
*/
/*
给你一个整数 n 和一个整数数组 rounds 。有一条圆形赛道由 n 个扇区组成，扇区编号从 1 到 n 。
现将在这条赛道上举办一场马拉松比赛，该马拉松全程由 m 个阶段组成。其中，
第 i 个阶段将会从扇区 rounds[i - 1] 开始，到扇区 rounds[i] 结束。举例来说，第 1 阶段从 rounds[0] 开始，到 rounds[1] 结束。
请你以数组形式返回经过次数最多的那几个扇区，按扇区编号 升序 排列。
注意，赛道按扇区编号升序逆时针形成一个圆（请参见第一个示例）。

提示：
2 <= n <= 100
1 <= m <= 100
rounds.length == m + 1
1 <= rounds[i] <= n
rounds[i] != rounds[i + 1] ，其中 0 <= i < m

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/most-visited-sector-in-a-circular-track
*/
class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        vector<int> cnt(n + 1, 0);
        int m = rounds.size();
        for(int i = 0; i < m - 1; ++i) {
            if(rounds[i] > rounds[i + 1]) {
                for(int j = rounds[i]; j <= n; ++j) cnt[j]++;
                for(int j = 1; j < rounds[i + 1]; ++j) cnt[j]++;
            } else {
                for(int j = rounds[i]; j < rounds[i + 1]; ++j) cnt[j]++;
            }
        }
        cnt[rounds[m - 1]]++;
        int mx = -1;
        for(int i = 1; i <= n; ++i) {
            mx = max(mx, cnt[i]);
        }
        vector<int> res;
        for(int i = 1; i <= n; ++i) {
            if(cnt[i] == mx) res.push_back(i);
        }
        return res;
    }
};