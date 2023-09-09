/*
* @Author: wilson_t
* @Date:   2020-08-04 12:08:36
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-04 12:10:19
*/
/*
* 题目[中等]：
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]
给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？

示例 1:
输入: 2, [[1,0]] 
输出: true
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。

示例 2:
输入: 2, [[1,0],[0,1]]
输出: false
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。
 
提示：
输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。
1 <= numCourses <= 10^5
*/
class Solution {
private:
    // vector<vector<int>> graph;
    // vector<int> indegree;
    // vector<bool> vis;
    // int n;
public:
    //dfs需要保存3种状态
    // bool dfs(int cur){
    //     vis[cur] = true;
    //     bool res = true;
    //     for(auto& v: graph[cur]){
    //         if(vis[v]){
    //             return false;
    //         }
    //         res = res && dfs(v);
    //     }
    //     return res;
    // }
    bool canFinish(int n, vector<vector<int>>& pre) {
        //loop check
        // this->n = _n;
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        vector<bool> vis(n, false);
        for(auto e: pre){
            graph[e[1]].push_back(e[0]);
            ++indegree[e[0]];
        }

        // for(int i = 0; i < n; ++i){
        //     if(!dfs(i))
        //         return false;
        // }
        // return true;

        //拓扑排序
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(indegree[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(auto& v: graph[cur]){
                if(vis[v]){
                    return false;
                }
                --indegree[v];
                if(indegree[v] == 0){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        for(int i = 0; i < n; ++i){
            if(!vis[i])
                return false;
        }
        return true;
    }
};