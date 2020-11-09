/*
* @Author: wilson_t
* @Date:   2020-11-09 19:58:20
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-09 20:06:41
*/
class Solution {
    static const int N = 1005;
    int C[N][N];
public:
    void generate(int n) {
        C[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0], h = destination[1];
        int n = v + h;
        string res = "";
        generate(v + h + 1);
        for(int i = 0; i < n; ++i) {
            if(h > 0) {
                int cnt = C[v + h - 1][h - 1];
                if(k > cnt) {
                    k -= cnt;
                    res.push_back('V');
                    --v;
                } else {
                    res.push_back('H');
                    --h;
                }
            } else {
                res.push_back('V');
                --v;
            }
        }
        return res;
    }
};