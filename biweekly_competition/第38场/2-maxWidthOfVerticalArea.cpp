/*
* @Author: wilson_t
* @Date:   2020-11-09 20:08:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:09:16
*/
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& pts) {
        sort(pts.begin(), pts.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int n = pts.size(), res = 0;
        for(int i = 1; i < n; ++i) {
            res = max(res, pts[i][0] - pts[i - 1][0]);
        }
        return res;
    }
};