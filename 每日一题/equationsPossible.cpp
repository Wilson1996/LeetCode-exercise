/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-08 00:05:59
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-08 01:00:10
*/
/*********************************************************
* 题目[中等]：
给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，
并采用两种不同的形式之一："a==b" 或 "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 

示例 1：
输入：["a==b","b!=a"]
输出：false
解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。

示例 2：
输出：["b==a","a==b"]
输入：true
解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。

示例 3：
输入：["a==b","b==c","a==c"]
输出：true

示例 4：
输入：["a==b","b!=c","c==a"]
输出：false

示例 5：
输入：["c==c","b==d","x!=z"]
输出：true
 
提示：
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] 和 equations[i][3] 是小写字母
equations[i][1] 要么是 '='，要么是 '!'
equations[i][2] 是 '='
*********************************************************/
class Solution
{
    int parent[26];
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
    void join(int x, int y)
    {
        int root1 = find(x);
        int root2 = find(y);
        if(root1 != root2)
        {
            parent[root2] = root1;
        }
    }
    bool equationsPossible(vector<string>& equations)
    {
        for(int i = 0; i < 26; ++i) parent[i] = i;
        vector<int> buffer;
        int n = equations.size();
        for(int i = 0; i < n; ++i)
        {
            auto& s = equations[i];
            if(s[1] == '=') join(s[0] - 'a', s[3] - 'a');
            else
            {
                if(find(s[0]-'a') == find(s[3]-'a'))
                    return false;
                buffer.push_back(i);
            }
        }
        for(auto& x : buffer)
        {
            auto& s = equations[x];
            if(find(s[0]-'a') == find(s[3]-'a'))
                return false;
        }
        return true;
    }
};