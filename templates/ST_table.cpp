/*
* @Author: wilson_t
* @Date:   2021-08-24 15:11:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-24 15:11:40
*/
template<int opt(int, int)>
struct ST {
    const static int MAXN = 200000;
    int u[MAXN][20], n;
    int lg[MAXN];

    ST() {
        init();
    }

    void init() {
        lg[0] = -1;
        for (int i = 1; i < MAXN; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
    }

    void build(int a[], int n) {
        this->n = n;
        for (int i = 0; i < n; ++i) u[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                u[i][j] = opt(u[i][j - 1], u[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    void build(const vector<int>& a) {
        this->n = a.size();
        for (int i = 0; i < n; ++i) u[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                u[i][j] = opt(u[i][j - 1], u[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int ask(int a, int b) {
        if (a > b) std::swap(a, b);
        int k = lg[b - a + 1];
        return opt(u[a][k], u[b - (1 << k) + 1][k]);
    }
};