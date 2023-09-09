/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-17 15:53:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-17 15:53:53
*/

//from zerotrac
class Solution
{
public:
    int check(const vector<vector<int>>& points, int u, int v, double xc, double yc, double r)
    {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            int x1 = points[i][0], y1 = points[i][1];
            double dist = (x1 - xc) * (x1 - xc) + (y1 - yc) * (y1 - yc);
            if (dist < r * r + 1e-7)
            {
                ++ans;
            }
        }
        return ans;
    }

    int numPoints(vector<vector<int>>& points, int r)
    {
        int n = points.size();
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; ++j)
            {
                int x2 = points[j][0], y2 = points[j][1];
                if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) > r * r * 4)
                {
                    continue;
                }
                double xm = (x1 + x2) / 2.0;
                double ym = (y1 + y2) / 2.0;
                double xdir = x1 - xm, ydir = y1 - ym;
                double norm = sqrt(xdir * xdir + ydir * ydir);
                xdir /= norm;
                ydir /= norm;
                double xc1 = -ydir, yc1 = xdir;
                double xc2 = ydir, yc2 = -xdir;
                double dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                double lent = sqrt(r * r - dist / 4);
                xc1 = xm + lent * xc1;
                yc1 = ym + lent * yc1;
                xc2 = xm + lent * xc2;
                yc2 = ym + lent * yc2;
                ans = max(ans, max(check(points, i, j, xc1, yc1, r), check(points, i, j, xc2, yc2, r)));
            }
        }
        return ans;
    }
};