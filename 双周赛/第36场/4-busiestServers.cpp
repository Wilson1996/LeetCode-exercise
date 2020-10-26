/*
* @Author: wilson_t
* @Date:   2020-10-03 20:22:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 00:19:24
*/
/*********************************************************
* 题目[困难]：
你有 k 个服务器，编号为 0 到 k-1 ，它们可以同时处理多个请求组。每个服务器有无穷的计算能力但是
不能同时处理超过一个请求 。请求分配到服务器的规则如下：
第 i （序号从 0 开始）个请求到达。
如果所有服务器都已被占据，那么该请求被舍弃（完全不处理）。
如果第 (i % k) 个服务器空闲，那么对应服务器会处理该请求。
否则，将请求安排给下一个空闲的服务器（服务器构成一个环，必要的话可能从第 0 个服务器开始继续找下一个空闲的服务器）。
比方说，如果第 i 个服务器在忙，那么会查看第 (i+1) 个服务器，第 (i+2) 个服务器等等。
给你一个 严格递增 的正整数数组 arrival ，表示第 i 个任务的到达时间，和另一个数组 load ，
其中 load[i] 表示第 i 个请求的工作量（也就是服务器完成它所需要的时间）。你的任务是找到 最繁忙的服务器 。
最繁忙定义为一个服务器处理的请求数是所有服务器里最多的。
请你返回包含所有 最繁忙服务器 序号的列表，你可以以任意顺序返回这个列表。

提示：
1 <= k <= 105
1 <= arrival.length, load.length <= 105
arrival.length == load.length
1 <= arrival[i], load[i] <= 109
arrival 保证 严格递增 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-servers-that-handled-most-number-of-requests
*********************************************************/
//优先队列 + set二分查找
using PII = pair<int, int>;
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& a, vector<int>& b) {
        vector<int> res;
        int n = a.size();
        vector<int> cnt(k, 0);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        set<int> Free;
        for(int i = 0; i < k; ++i) Free.insert(i);
        for(int i = 0; i < n; ++i) {
            while(!pq.empty() && pq.top().first <= a[i]) {
                Free.insert(pq.top().second);
                pq.pop();
            }
            if(!Free.empty()) {
                auto it = Free.lower_bound(i % k);
                if(it == Free.end()) it = Free.begin();
                int id = *it;
                Free.erase(it);
                cnt[id]++;
                pq.emplace(a[i] + b[i], id);
            }
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        for(int i = 0; i < k; ++i) {
            if(cnt[i] == mx) res.emplace_back(i);
        }
        return res;
    }
};