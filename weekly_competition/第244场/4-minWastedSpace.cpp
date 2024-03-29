/*
* @Author: wilson_t
* @Date:   2021-06-06 18:05:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-13 10:17:30
*/
/*
给你n个包裹，你需要把它们装在箱子里，每个箱子装一个包裹。总共有m个供应商提供 不同尺寸的箱子（每个规格都有无数个箱子）。
如果一个包裹的尺寸 小于等于一个箱子的尺寸，那么这个包裹就可以放入这个箱子之中。
包裹的尺寸用一个整数数组packages表示，其中packages[i]是第i个包裹的尺寸。供应商用二维数组boxes表示，
其中boxes[j]是第 j个供应商提供的所有箱子尺寸的数组。
你想要选择 一个供应商并只使用该供应商提供的箱子，使得 总浪费空间最小。对于每个装了包裹的箱子，我们定义 浪费的空间等于 箱子的尺寸 - 包裹的尺寸。总浪费空间为所有箱子中浪费空间的总和。
比方说，如果你想要用尺寸数组为[4,8]的箱子装下尺寸为[2,3,5]的包裹，你可以将尺寸为 2和 3的两个包裹装入两个尺寸为 4的箱子中，同时把尺寸为 5的包裹装入尺寸为 8的箱子中。总浪费空间为(4-2) + (4-3) + (8-5) = 6。
请你选择 最优箱子供应商，使得 总浪费空间最小。如果 无法 将所有包裹放入箱子中，请你返回 -1。由于答案可能会 很大，请返回它对109 + 7取余的结果。

示例 1：
输入：packages = [2,3,5], boxes = [[4,8],[2,8]]
输出：6
解释：选择第一个供应商最优，用两个尺寸为 4 的箱子和一个尺寸为 8 的箱子。
总浪费空间为 (4-2) + (4-3) + (8-5) = 6 。

示例 2：
输入：packages = [2,3,5], boxes = [[1,4],[2,3],[3,4]]
输出：-1
解释：没有箱子能装下尺寸为 5 的包裹。

示例 3：
输入：packages = [3,5,8,10,11,12], boxes = [[12],[11,9],[10,5,14]]
输出：9
解释：选择第三个供应商最优，用两个尺寸为 5 的箱子，两个尺寸为 10 的箱子和两个尺寸为 14 的箱子。
总浪费空间为 (5-3) + (5-5) + (10-8) + (10-10) + (14-11) + (14-12) = 9 。

提示：
n == packages.length
m == boxes.length
1 <= n <= 105
1 <= m <= 105
1 <= packages[i] <= 105
1 <= boxes[j].length <= 105
1 <= boxes[j][k] <= 105
sum(boxes[j].length) <= 105
boxes[j]中的元素 互不相同。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-space-wasted-from-packaging
 */
using ll = long long;
const int mod = 1'000'000'007;

class Solution {
public:
    int minWastedSpace(vector<int>& pack, vector<vector<int>>& boxes) {
        ll res = LONG_LONG_MAX;
        int n = pack.size(), m = boxes.size();
        sort(pack.begin(), pack.end());
        vector<ll> pre(n + 1, 0);
        for(int i = 0; i < n; ++i) pre[i + 1] = pre[i] + pack[i];
        for(int b = 0; b < m; ++b) {
            auto& box = boxes[b];
            int len = box.size();
            sort(box.begin(), box.end());
            ll nowRes = 0;
            int lastIdx = 0;
            for(int j = 0; j < len; ++j) {
                int now = box[j];
                int idx = upper_bound(pack.begin(), pack.end(), now) - pack.begin();
                nowRes += (ll)now * (idx - lastIdx) - (pre[idx] - pre[lastIdx]);
                lastIdx = idx;
            }
            if(lastIdx >= n) {
                res = min(res, nowRes);
            }
        }

        return res == LONG_LONG_MAX ? -1 : res % mod;
    }
};