/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-31 10:35:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-31 13:22:15
*/
//from zerotrac
using LL = long long;
class Solution
{
private:
    int target;
    double p, q;
    double fac[25];
    vector<int> allocate;

public:
    void dfs(const vector<int>& balls, int pos, int occ, int balance)
    {
        if (pos == balls.size())
        {
            if (occ == target)
            {
                double u = fac[target] * fac[target];
                for (int i = 0; i < balls.size(); ++i)
                {
                    u /= fac[allocate[i]];
                    u /= fac[balls[i] - allocate[i]];
                }
                if (!balance)
                {
                    p += u;
                }
                q += u;
            }
            return;
        }
        int could = min(target - occ, balls[pos]);
        for (int i = 0; i <= could; ++i)
        {
            allocate[pos] = i;
            dfs(balls, pos + 1, occ + i, balance + (i == 0 ? -1 : (i == balls[pos] ? 1 : 0)));
        }
    }

    double getProbability(vector<int>& balls)
    {
        allocate.resize(balls.size());
        fac[0] = 1;
        for (int i = 1; i <= 24; ++i)
        {
            fac[i] = fac[i - 1] * i;
        }
        target = accumulate(balls.begin(), balls.end(), 0) / 2;
        p = q = 0;
        dfs(balls, 0, 0, 0);
        // cout << p << " " << q << "\n";
        return p / q;
    }
};