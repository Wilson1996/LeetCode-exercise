/*
* @Author: wilson_t
* @Date:   2020-11-04 09:52:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-04 09:54:49
*/
/*
* 题目[困难？]
给出一个无重叠的 ，按照区间起始端点排序的区间列表。
在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1：
输入：intervals = [[1,3],[6,9]], newInterval = [2,5]
输出：[[1,5],[6,9]]

示例 2：
输入：intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出：[[1,2],[3,10],[12,16]]
解释：这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

Constraints:
0 <= intervals.length <= 104
intervals[i].length == 2
0 <= intervals[i][0] <= intervals[i][1] <= 105
intervals is sorted by intervals[i][0] in ascending order.
newInterval.length == 2
0 <= newInterval[0] <= newInterval[1] <= 105

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;
        int i = 0, start = newInterval[0], end = newInterval[1];
        for(; i < n; ++i) {
            if(intervals[i][1] < newInterval[0]) res.emplace_back(intervals[i]);
            else {
                start = min(newInterval[0], intervals[i][0]);
                break;
            }
        }
        if(i < n && newInterval[1] < intervals[i][0]) {
            end = newInterval[1];
        } else if(i < n && intervals[i][1] >= newInterval[1]) {
            end = intervals[i][1];
            ++i;
        } else {
            ++i;
            for(; i < n; ++i) {
                if(intervals[i][0] > newInterval[1]) {
                    end = newInterval[1];
                    break;
                } else if(intervals[i][1] >= newInterval[1]) {
                    end = max(newInterval[1], intervals[i][1]);
                    ++i;
                    break;
                }
            }
        }
        res.emplace_back(vector<int> {start, end});
        for(; i < n; ++i) {
            res.emplace_back(intervals[i]);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }
        while(i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);
        while(i < intervals.size())
            res.push_back(intervals[i++]);
        return res;
    }
};