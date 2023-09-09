/*
一个数组的 最小乘积 定义为这个数组中 最小值 乘以 数组的 和 。
比方说，数组 [3,2,5] （最小值是 2）的最小乘积为 2 * (3+2+5) = 2 * 10 = 20 。
给你一个正整数数组 nums ，请你返回 nums 任意 非空子数组 的最小乘积 的 最大值 。由于答案可能很大，请你返回答案对  109 + 7 取余 的结果。
请注意，最小乘积的最大值考虑的是取余操作 之前 的结果。题目保证最小乘积的最大值在 不取余 的情况下可以用 64 位有符号整数 保存。
子数组 定义为一个数组的 连续 部分。

示例 1：
输入：nums = [1,2,3,2]
输出：14
解释：最小乘积的最大值由子数组 [2,3,2] （最小值是 2）得到。
2 * (2+3+2) = 2 * 7 = 14 。

示例 2：
输入：nums = [2,3,3,1,2]
输出：18
解释：最小乘积的最大值由子数组 [3,3] （最小值是 3）得到。
3 * (3+3) = 3 * 6 = 18 。

示例 3：
输入：nums = [3,1,5,6,4,2]
输出：60
解释：最小乘积的最大值由子数组 [5,6,4] （最小值是 4）得到。
4 * (5+6+4) = 4 * 15 = 60 。

提示：
1 <= nums.length <= 105
1 <= nums[i] <= 107
 */

//单调栈+前缀和
const int mod = 1e9 + 7;
using ll = long long;
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll> preSum(n + 1, 0);
        for(int i = 0; i < n; ++i) {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        ll res = 0;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<int> sk;
        for(int i = 0; i < n; ++i) {
            while(!sk.empty() && nums[sk.top()] >= nums[i])
                sk.pop();
            left[i] = sk.empty() ? -1 : sk.top();
            // left[i] = sk.empty() ? 0 : sk.top();

            sk.push(i);
        }
        sk = stack<int>();
        for(int i = n - 1; i >= 0; --i) {
            while(!sk.empty() && nums[sk.top()] >= nums[i])
                sk.pop();
            // right[i] = sk.empty() ? n : sk.top();
            right[i] = sk.empty() ? n : sk.top();
            sk.push(i);
        }
        for(int i = 0; i < n; ++i) {
            ll lsum = 0, rsum = 0;
            if(right[i] == n) rsum = preSum[n];
            else rsum = preSum[right[i]];
            if(left[i] == -1) lsum = 0;
            else lsum = preSum[left[i] + 1];
            res = max(res, (ll)nums[i] * (rsum - lsum));
        }
        return res % mod;
    }
};


//from huangyuyang
//排序+并查集
int f[100005], flag[100005];
long long s[100005];

class Solution {
public:
    int find(int i) {
        return f[i] == i ? i : f[i] = find(f[i]);
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        s[a] += s[b];
        f[b] = a;
    }

    int maxSumMinProduct(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector <pair <int, int> > v;
        for (int i = 0; i < n; i++) {
            f[i] = i;
            flag[i] = 0;
            s[i] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            v.push_back(make_pair(nums[i], i));
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {
            int pos = v[i].second;
            if (pos > 0 && flag[pos - 1]) {
                merge(pos, pos - 1);
            }
            if (pos < n - 1 && flag[pos + 1]) {
                merge(pos, pos + 1);
            }
            flag[pos] = 1;
            int a = find(pos);
            ans = max(ans, s[a] * v[i].first);
        }
        return (int)(ans % (int)(1e9 + 7));
    }
};