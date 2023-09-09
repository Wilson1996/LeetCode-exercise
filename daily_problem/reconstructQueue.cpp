/*
* @Author: wilson_t
* @Date:   2020-11-16 13:17:50
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-16 13:18:29
*/
/**
* 题目[中等]：
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，
k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例
输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
 */
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        vector<vector<int>> res(n);
        sort(people.begin(), people.end(), [&](const vector<int>& a, const vector<int>& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });
        // for(int i = 0; i <n; ++i) {
        //     printf("[%d,%d], ", people[i][0], people[i][1]);
        // }
        for (const vector<int>& person : people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (res[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        res[i] = person;
                        break;
                    }
                }
            }
        }
        return res;
    }
};