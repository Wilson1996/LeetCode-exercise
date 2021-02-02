/*
* @Author: wilson_t
* @Date:   2021-01-17 20:03:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-17 20:03:25
*/
class Solution {
    vector<int> origin;
public:
    Solution(vector<int> nums): origin(std::move(nums)) {}
    vector<int> reset() {
        return origin;
    }
    vector<int> shuffle() {
        if (origin.empty()) return {};
        vector<int> shuffled(origin);
        int n = origin.size();
        // 可以使用反向或者正向洗牌，效果相同。
        // 反向洗牌：
        for (int i = n - 1; i >= 0; --i) {
            swap(shuffled[i], shuffled[rand() % (i + 1)]);
        }
        // 正向洗牌：
        // for (int i = 0; i < n; ++i) {
        // int pos = rand() % (n - i);
        // swap(shuffled[i], shuffled[i+pos]);
        // }
        return shuffled;
    }
};