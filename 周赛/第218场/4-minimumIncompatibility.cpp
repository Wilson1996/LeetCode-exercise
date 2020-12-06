/*
* @Author: wilson_t
* @Date:   2020-12-06 15:00:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-06 15:01:37
*/
/*
给你一个整数数组 nums​​​ 和一个整数 k 。你需要将这个数组划分到 k 个相同大小的子集中，使得同一个子集里面没有两个相同的元素。
一个子集的 不兼容性 是该子集里面最大值和最小值的差。
请你返回将数组分成 k 个子集后，各子集 不兼容性 的 和 的 最小值 ，如果无法分成分成 k 个子集，返回 -1 。
子集的定义是数组中一些数字的集合，对数字顺序没有要求。 

示例 1：
输入：nums = [1,2,1,4], k = 2
输出：4
解释：最优的分配是 [1,2] 和 [1,4] 。
不兼容性和为 (2-1) + (4-1) = 4 。
注意到 [1,1] 和 [2,4] 可以得到更小的和，但是第一个集合有 2 个相同的元素，所以不可行。

示例 2：
输入：nums = [6,3,8,1,3,1,2,2], k = 4
输出：6
解释：最优的子集分配为 [1,2]，[2,3]，[6,8] 和 [1,3] 。
不兼容性和为 (2-1) + (3-2) + (8-6) + (3-1) = 6 。

示例 3：
输入：nums = [5,3,3,6,3,3], k = 3
输出：-1
解释：没办法将这些数字分配到 3 个子集且满足每个子集里没有相同数字。

提示：
1 <= k <= nums.length <= 16
nums.length 能被 k 整除。
1 <= nums[i] <= nums.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-incompatibility
*/
const int maxn = (1 << 16);
int valid[maxn + 5];
int f[maxn + 5];
int cnt[20];
class Solution {
public:
    //状态压缩+子集枚举
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        memset(valid, -1, sizeof(int) * ((1 << n) + 5));
        memset(f, -1, sizeof(int) * ((1 << n) + 5));
        //预处理可行的子集
        for(int i = 0; i < (1 << n); ++i) {
            if(__builtin_popcount(i) == n / k) {
                memset(cnt, 0, sizeof(cnt));
                for(int j = 0; j < n; ++j) {
                    if(i & (1 << j)) {
                        ++cnt[nums[j]];
                    }
                }
                bool flag = true;
                for(int l = 1; l <= n; ++l) {
                    if(cnt[l] > 1) {
                        flag = false;
                        break;
                    }
                }
                if(flag) {
                    int mi = INT_MAX, mx = INT_MIN;
                    for(int l = 1; l <= n; ++l) {
                        if(cnt[l] > 0) {
                            mi = min(mi, l);
                            mx = max(mx, l);
                        }
                    }
                    valid[i] = mx - mi;
                }
            }
        }

        //枚举子集
        f[0] = 0;
        for(int mask = 0; mask < (1 << n); ++mask) {
            if(__builtin_popcount(mask) % (n / k) == 0) {
                for(int sub = mask; sub != 0; sub = (sub - 1)&mask) {
                    if(valid[sub] != -1 && f[mask ^ sub] != -1) {
                        if(f[mask] == -1) {
                            f[mask] = f[mask ^ sub] + valid[sub];
                        } else {
                            f[mask] = min(f[mask], f[mask ^ sub] + valid[sub]);
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};