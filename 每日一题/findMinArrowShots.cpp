/*
* @Author: wilson_t
* @Date:   2020-11-23 00:36:32
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-23 00:36:45
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) {
            if(a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
        });
        int i = 0;
        while(i < n) {
            int start = points[i][0], end = points[i][1];
            while(i < n && points[i][0] <= end) {
                start = points[i][0];
                end = min(end, points[i][1]);
                ++i;
            }
            ++res;
        }
        return res;
    }
};