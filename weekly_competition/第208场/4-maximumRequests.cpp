/*
* @Author: wilson_t
* @Date:   2020-09-27 10:15:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-27 12:43:37
*/
/*
我们有 n 栋楼，编号从 0 到 n - 1 。每栋楼有若干员工。由于现在是换楼的季节，部分员工想要换一栋楼居住。
给你一个数组 requests ，其中 requests[i] = [fromi, toi] ，表示一个员工请求从编号为 fromi 的楼搬到编号为 toi 的楼。
一开始 所有楼都是满的，所以从请求列表中选出的若干个请求是可行的需要满足 每栋楼员工净变化为 0 。
意思是每栋楼 离开 的员工数目 等于 该楼 搬入 的员工数数目。比方说 n = 3 且两个员工要离开楼 0 ，
一个员工要离开楼 1 ，一个员工要离开楼 2 ，如果该请求列表可行，应该要有两个员工搬入楼 0 ，一个员工搬入楼 1 ，一个员工搬入楼 2 。
请你从原请求列表中选出若干个请求，使得它们是一个可行的请求列表，并返回所有可行列表中最大请求数目。

示例 1：
输入：n = 5, requests = [[0,1],[1,0],[0,1],[1,2],[2,0],[3,4]]
输出：5
解释：请求列表如下：
从楼 0 离开的员工为 x 和 y ，且他们都想要搬到楼 1 。
从楼 1 离开的员工为 a 和 b ，且他们分别想要搬到楼 2 和 0 。
从楼 2 离开的员工为 z ，且他想要搬到楼 0 。
从楼 3 离开的员工为 c ，且他想要搬到楼 4 。
没有员工从楼 4 离开。
我们可以让 x 和 b 交换他们的楼，以满足他们的请求。
我们可以让 y，a 和 z 三人在三栋楼间交换位置，满足他们的要求。
所以最多可以满足 5 个请求。

示例 2：
输入：n = 3, requests = [[0,0],[1,2],[2,1]]
输出：3
解释：请求列表如下：
从楼 0 离开的员工为 x ，且他想要回到原来的楼 0 。
从楼 1 离开的员工为 y ，且他想要搬到楼 2 。
从楼 2 离开的员工为 z ，且他想要搬到楼 1 。
我们可以满足所有的请求。

示例 3：
输入：n = 4, requests = [[0,3],[3,1],[1,2],[2,0]]
输出：4
 
提示：
1 <= n <= 20
1 <= requests.length <= 16
requests[i].length == 2
0 <= fromi, toi < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-achievable-transfer-requests
*/

//dfs状态枚举
class Solution {
    int num, res, n;
    vector<vector<int>> req;
    int log[25];
public:
    bool check() {
        for(int i = 0; i < n; ++i) {
            if(log[i] != 0) return false;
        }
        return true;
    }
    void dfs(int cur, int times) {
        if(cur == num) {
            if(check()) res = max(res, times);
            return;
        }
        log[req[cur][0]]--;
        log[req[cur][1]]++;
        dfs(cur + 1, times + 1);
        log[req[cur][0]]++;
        log[req[cur][1]]--;
        dfs(cur + 1, times);
    }
    int maximumRequests(int _n, vector<vector<int>>& requests) {
        n = _n;
        num = requests.size();
        req = requests;
        res = 0;
        for(int i = 0; i < n; ++i) log[i] = 0;
        dfs(0, 0);
        return res;
    }
};

//二进制枚举（from zerotrac）
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& a) {
        int cnt[20];
        int m = a.size();
        int ans = 0;
        for (int mask = 1; mask < (1 << m); ++mask) {
            memset(cnt, 0, sizeof(cnt));
            for (int j = 0; j < m; ++j) {
                if (mask & (1 << j)) {
                    --cnt[a[j][0]];
                    ++cnt[a[j][1]];
                }
            }
            bool check = true;
            for (int i = 0; i < n; ++i) {
                if (cnt[i] != 0) {
                    check = false;
                    break;
                }
            }
            if (check) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        return ans;
    }
};