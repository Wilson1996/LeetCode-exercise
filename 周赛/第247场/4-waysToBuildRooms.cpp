/*
* @Author: wilson_t
* @Date:   2021-06-27 20:04:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-27 20:05:41
*/
/*
你是一只蚂蚁，负责为蚁群构筑 n 间编号从 0 到 n-1 的新房间。给你一个 下标从 0 开始 且长度为 n 的整数数组prevRoom 作为扩建计划。
其中，prevRoom[i] 表示在构筑房间 i 之前，你必须先构筑房间 prevRoom[i] ，并且这两个房间必须 直接 相连。房间 0 已经构筑完成，所以 prevRoom[0] = -1 。
扩建计划中还有一条硬性要求，在完成所有房间的构筑之后，从房间 0 可以访问到每个房间。
你一次只能构筑 一个 房间。你可以在 已经构筑好的 房间之间自由穿行，只要这些房间是 相连的 。如果房间prevRoom[i] 已经构筑完成，那么你就可以构筑房间 i。
返回你构筑所有房间的 不同顺序的数目 。由于答案可能很大，请返回对 109 + 7 取余 的结果。

提示：
n == prevRoom.length
2 <= n <= 105
prevRoom[0] == -1
对于所有的1 <= i < n，都有0 <= prevRoom[i] < n
题目保证所有房间都构筑完成后，从房间 0 可以访问到每个房间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-ways-to-build-rooms-in-an-ant-colony
 */
using ll = long long;
using pli = pair<long long, int>;
const int mod = 1'000'000'007;
const int maxn = 100005;
ll fac[maxn], inv[maxn], facInv[maxn];
void calc_fac_facInv() {
    fac[0] = inv[0] = facInv[0] = 1;
    fac[1] = inv[1] = facInv[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        fac[i] = (long long)fac[i - 1] * i % mod;
        inv[i] = (long long)(mod - mod / i) * inv[mod % i] % mod;
        facInv[i] = (long long)facInv[i - 1] * inv[i] % mod;
    }
}
struct INIT {
    INIT() {
        calc_fac_facInv();
    }
} __init__;

class Solution {
    int n;
    vector<vector<int>> tree;
public:
    // (ways, nodes_cnt)
    pli dfs(int cur) {
        if(tree[cur].size() == 0) {
            return {1LL, 1};
        }
        long long res = 1;
        int cnt = 0;
        for(int v : tree[cur]) {
            pli now = dfs(v);
            res = res * now.first % mod * facInv[now.second] % mod;
            cnt += now.second;
        }
        res = res * fac[cnt] % mod;
        return {res, cnt + 1};
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        n = prevRoom.size();
        tree = vector<vector<int>>(n);
        for(int i = 1; i < n; ++i) {
            tree[prevRoom[i]].emplace_back(i);
        }
        auto [res, cnt] = dfs(0);
        return res % mod;
    }
};