/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-25 23:00:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-25 23:26:14
*/
/*********************************************************
* 题目[中等]：
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，
表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。你必须输出所有学生中的已知的朋友圈总数。

示例 1:
输入:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。

示例 2:
输入:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。

注意：
N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。
*********************************************************/
#include <iostream>
#include <vector>
using namespace std;

//方法一：并查集
//方法二：DFS, BFS
class Solution
{
    int parent[200];
public:
    int find(int x)
    {
        int son = x;
        while(parent[x] != x)
            x = parent[x];
        //路径压缩
        while(son != x)
        {
            int tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }
        return x;
    }
    void join(int a, int b)
    {
        int root1 = find(a);
        int root2 = find(b);
        if(root1 != root2)
        {
            parent[root2] = root1;
        }
    }
    int findCircleNum(vector<vector<int>>& M)
    {
        int N = M.size();
        //初始化parent数组
        for(int i = 0; i < N; ++i)
        {
            parent[i] = i;
        }
        for(int i = 0; i < N; ++i)
        {
            for(int j = i + 1; j < N; ++j)
            {
                if(M[i][j])
                {
                    join(i, j);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < N; ++i)
        {
            if(parent[i] == i)
                ++res;
        }
        return res;
    }
};