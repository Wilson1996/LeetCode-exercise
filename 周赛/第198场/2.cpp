/*
* @Author: wilson_t
* @Date:   2020-07-20 17:13:25
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-07-25 00:05:33
*/
/*********************************************************
* 题目[中等]：
给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n 个节点组成，且恰好有 n - 1 条 edges 。
树的根节点为节点 0 ，树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为 i 的 节点的标签就是 labels[i] ）
边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi 之间存在一条边。
返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i 标签相同的节点数。
树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。

示例 1：
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
输出：[2,1,1,1,1,1,1]
解释：节点 0 的标签为 'a' ，以 'a' 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2 。注意树中的每个节点都是这棵子树的一部分。
节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。

提示：
1 <= n <= 10^5
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
labels.length == n
labels 仅由小写英文字母组成
*********************************************************/

//dfs会超时
class Solution2 {
    vector<vector<int>> tree;   
    map<pair<int, char>, int> mp;
public:
    int dfs(int cur, char label, string& labels){
        if(mp.find({cur, label}) != mp.end())
            return mp[{cur, label}];
        int res = 0;
        if(labels[cur] == label) ++res;
        for(auto& v : tree[cur]){
            // if(vis[v] || localVis[v]) continue;
            int tmp = dfs(v, label, labels);
            // mp[{v, label}] = tmp;
            res += tmp;
        }
        mp[{cur, label}] = res;
        return res;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> tree_tmp = vector<vector<int>> (n);
        for(auto& e : edges){
            tree_tmp[e[0]].push_back(e[1]);
            tree_tmp[e[1]].push_back(e[0]);
        }
        tree = vector<vector<int>> (n);
        vector<bool> vis = vector<bool> (n, false);;
        queue<int> Q;
        Q.push(0);
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            vis[cur] = true;
            for(auto& v : tree_tmp[cur]){
                if(vis[v]) continue;
                tree[cur].push_back(v);
                Q.push(v);
            }
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; ++i){
            res[i] = dfs(i, labels[i], labels);
        }
        return res;
    }
};

class Solution{
private:
	f[10005][26];
public:
	vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		
	}
};