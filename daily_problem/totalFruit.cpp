/*
* @Author: wilson_t
* @Date:   2020-09-25 21:34:29
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-25 21:36:11
*/
/*********************************************************
* 题目[中等]：
在一排树中，第 i 棵树产生 tree[i] 型的水果。
你可以从你选择的任何树开始，然后重复执行以下步骤：
把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。
你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
用这个程序你能收集的水果树的最大总量是多少？

示例 1：
输入：[1,2,1]
输出：3
解释：我们可以收集 [1,2,1]。

示例 2：
输入：[0,1,2,2]
输出：3
解释：我们可以收集 [1,2,2]
如果我们从第一棵树开始，我们将只能收集到 [0, 1]。

示例 3：
输入：[1,2,3,2,2]
输出：4
解释：我们可以收集 [2,3,2,2]
如果我们从第一棵树开始，我们将只能收集到 [1, 2]。

示例 4：
输入：[3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：我们可以收集 [1,2,1,1,2]
如果我们从第一棵树或第八棵树开始，我们将只能收集到 4 棵水果树。

提示：
1 <= tree.length <= 40000
0 <= tree[i] < tree.length

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fruit-into-baskets
*********************************************************/
//滑动窗口，哈希表记录
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int n = tree.size(), l = 0, r = 0, res = 0;
        unordered_map<int, int> mp;
        while(r < n) {
            mp[tree[r++]]++;
            if(mp.size() > 2) {
                while(mp.size() > 2) {
                    mp[tree[l]]--;
                    if(mp[tree[l]] == 0) mp.erase(tree[l]);
                    l++;
                }
            }
            res = max(res, r - l);
            // printf("l=%d, r=%d\n", l, r);
        }
        res = max(res, r - l);
        return res;
    }
};

//左中右判断
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, left = 0, right = -1, n = tree.size();
        for (int i = 1; i < n; ++i) {
            if (tree[i] == tree[i - 1]) continue;
            if (right >= 0 && tree[right] != tree[i]) {
                res = max(res, i - left);
                left = right + 1;
            }
            right = i - 1;
        }
        return max(n - left, res);
    }
};