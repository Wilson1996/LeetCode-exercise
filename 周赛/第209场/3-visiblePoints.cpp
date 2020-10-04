/*
* @Author: wilson_t
* @Date:   2020-10-03 20:24:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-04 21:47:33
*/
/*
给你一个点数组 points 和一个表示角度的整数 angle ，你的位置是 location ，
其中 location = [posx, posy] 且 points[i] = [xi, yi] 都表示 X-Y 平面上的整数坐标。
最开始，你面向东方进行观测。你 不能 进行移动改变位置，但可以通过 自转 调整观测角度。
换句话说，posx 和 posy 不能改变。你的视野范围的角度用 angle 表示， 这决定了你观测任意方向时可以多宽。设 d 为逆时针旋转的度数，
那么你的视野就是角度范围 [d - angle/2, d + angle/2] 所指示的那片区域。
对于每个点，如果由该点、你的位置以及从你的位置直接向东的方向形成的角度 位于你的视野中 ，那么你就可以看到它。
同一个坐标上可以有多个点。你所在的位置也可能存在一些点，但不管你的怎么旋转，总是可以看到这些点。同时，点不会阻碍你看到其他点。
返回你能看到的点的最大数目。

提示：
1 <= points.length <= 105
points[i].length == 2
location.length == 2
0 <= angle < 360
0 <= posx, posy, xi, yi <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-number-of-visible-points
*/
const double pi = 3.14159265358979323846264;
class Solution {
public:
    int visiblePoints(vector<vector<int>>& pts, int ang, vector<int>& loc) {
        int n = pts.size(), res = 0;
        vector<double> dir;
        for(int i = 0; i < n; ++i) {
            if(pts[i][1] == loc[1] && pts[i][0] == loc[0]) ++res;
            else {
                double tmp = atan2(pts[i][1] - loc[1], pts[i][0] - loc[0]) * 180 / pi;
                if(tmp < 0) tmp += 360;
                dir.emplace_back(tmp);
            }
        }
        sort(dir.begin(), dir.end());
        int m = dir.size(), mx = 0, l = 0, r = 0;
        double end = dir.back() + ang;
        for(int i = 0; i < m; ++i) {
            if(dir[i] + 360 <= end) dir.emplace_back(dir[i] + 360);
            else break;
        }
        m = dir.size();
        while(r < m) {
            if(dir[r] - dir[l] <= ang) ++r;
            else {
                mx = max(mx, r - l);
                ++l;
            }
        }
        mx = max(mx, r - l);
        return res + mx;
    }
};