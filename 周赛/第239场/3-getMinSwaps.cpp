/*
* @Author: wilson_t
* @Date:   2021-05-02 14:17:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-05-02 14:18:07
*/
/*
给你一个表示大整数的字符串 num ，和一个整数 k 。
如果某个整数是 num 中各位数字的一个 排列 且它的 值大于 num ，则称这个整数为 妙数 。可能存在很多妙数，但是只需要关注 值最小 的那些。
例如，num = "5489355142" ：
第 1 个最小妙数是 "5489355214"
第 2 个最小妙数是 "5489355241"
第 3 个最小妙数是 "5489355412"
第 4 个最小妙数是 "5489355421"
返回要得到第 k 个 最小妙数 需要对 num 执行的 相邻位数字交换的最小次数 。
测试用例是按存在第 k 个最小妙数而生成的。

示例 1：
输入：num = "5489355142", k = 4
输出：2
解释：第 4 个最小妙数是 "5489355421" ，要想得到这个数字：
- 交换下标 7 和下标 8 对应的位："5489355142" -> "5489355412"
- 交换下标 8 和下标 9 对应的位："5489355412" -> "5489355421"

示例 2：
输入：num = "11112", k = 4
输出：4
解释：第 4 个最小妙数是 "21111" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："11112" -> "11121"
- 交换下标 2 和下标 3 对应的位："11121" -> "11211"
- 交换下标 1 和下标 2 对应的位："11211" -> "12111"
- 交换下标 0 和下标 1 对应的位："12111" -> "21111"

示例 3：
输入：num = "00123", k = 1
输出：1
解释：第 1 个最小妙数是 "00132" ，要想得到这个数字：
- 交换下标 3 和下标 4 对应的位："00123" -> "00132"
 
提示：
2 <= num.length <= 1000
1 <= k <= 1000
num 仅由数字组成

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number
 */
class Solution {
public:
    void nextPermutation(string& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[i] >= nums[j]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }

    int getStep(string& from, string& to, int start) {
        int n = from.size(), res = 0;
        if(start >= n) return 0;
        while(start < n && from[start] == to[start]) ++start;
        int i = start;
        while(i < n && from[i] != to[start]) ++i;
        res += (i - start);
        for(int j = i; j > start; --j) swap(from[j], from[j - 1]);
        return res + getStep(from, to, start + 1);
    }

    int getMinSwaps(string num, int k) {
        int n = num.size();
        string to = num;
        for(int i = 0; i < k; ++i) {
            nextPermutation(to);
        }
        // cout << to << "\n";

        return getStep(num, to, 0);
    }
};