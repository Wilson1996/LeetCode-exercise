/*
* @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
* @Date:   2020-10-14 23:41:45
* @Last Modified by:   Wilson.T
* @Last Modified time: 2020-10-14 23:58:58
*/
/*
给定一张n(n<=20)个点的带权无向图，点从0~n-1标号，求起点0到终点n-1的最短Hamilton路径。
 */
//f[i][j]: i的二进制位表示哪些点已经被经过，j表示当前所在的点
int f[1 << 20][20];
int hamilton(int n, int weight[20][20]) {
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for(int i = 1; i < (1 << n); ++i) {
        for(int j = 0; j < n; ++j) {
            if((i >> j) & 1) {
                for(int k = 0; k < n; ++k) {
                    if((i ^ (1 << j)) >> k & 1) {
                        f[i][j] = min(f[i][j], f[(i ^ (1 << j))][k] + weight[k][j]);
                    }
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}
