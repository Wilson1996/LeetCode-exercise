/*
* @Author: wilson_t
* @Date:   2021-08-27 15:50:56
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-08-27 16:30:51
*/
/*
匈牙利算法
cx[i]表示与X部i点匹配的Y部顶点编号
cy[i]表示与Y部i点匹配的X部顶点编号
*/
/*
//伪代码
bool dfs(int u) { //寻找从u出发的增广路径
    for each v∈u的邻接点
    if(v未访问) {
            标记v已访问;
            if(v未匹配 || dfs(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return true;//有从u出发的增广路径
            }
        }
    return false;//无法找到从u出发的增广路径
}
*/
//代码
bool dfs(int u) {
    for(int v = 1; v <= m; v++) {
        if(t[u][v] && !vis[v]) {
            vis[v] = 1;
            if(cy[v] == -1 || dfs(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
void maxmatch() { //匈牙利算法主函数
    int ans = 0;
    memset(cx, 0xff, sizeof cx);
    memset(cy, 0xff, sizeof cy);
    for(int i = 0; i <= nx; i++) {
        if(cx[i] == -1) {
            //如果i未匹配
            memset(visit, false, sizeof(visit)) ;
            ans += dfs(i);
        }
    }
    return ans ;
}
