/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-24 13:47:19
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-25 17:41:01
*/
/*********************************************************
* 题目[困难]：
给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例:
输入: 4
输出: [
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。
 
提示：
皇后，是国际象棋中的棋子，意味着国王的妻子。皇后只做一件事，那就是“吃子”。当她遇见可以吃的棋子时，
就迅速冲上去吃掉棋子。当然，她横、竖、斜都可走一到七步，可进可退。（引用自 百度百科 - 皇后 ）
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<string>> res;
    vector<int> Qpos;
    vector<bool> vis_pos;//用来标记正斜率对角线是否访问
    vector<bool> vis_neg;//用来标记负斜率对角线
    vector<bool> vis_col;//用来标记列
    int n;
public:
    void dfs(int cur)
    {
        if(cur == n)
        {
            vector<string> pos(n);
            for(int i = 0; i < n; ++i)
            {
                pos[i] = string(n, '.');
                pos[i][Qpos[i]] = 'Q';
            }
            res.push_back(pos);
            return;
        }
        for(int i = 0; i < n; ++i)
        {
            if(!vis_col[i] && !vis_pos[cur - i + n - 1] && !vis_neg[cur + i])
            {
                Qpos[cur] = i;
                vis_col[i] = true;
                vis_pos[cur - i + n - 1] = true;
                vis_neg[cur + i] = true;
                dfs(cur + 1);
                vis_col[i] = false;
                vis_pos[cur - i + n - 1] = false;
                vis_neg[cur + i] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int _n)
    {
        n = _n;
        Qpos = vector<int>(n);
        vis_pos = vector<bool>(2 * n, false);
        vis_neg = vector<bool>(2 * n, false);
        vis_col = vector<bool>(n, false);
        dfs(0);
        return res;
    }
};

//方法二：位运算
class Solution2
{
private:
    int res;
public:
    int totalNQueens(int n)
    {
        res = 0;
        dfs(n, 0, 0, 0, 0);
        return res;
    }

    void dfs(int n, int row, int col, int ld, int rd)
    {
        if (row >= n) { res++; return; }
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历
        int bits = ~(col | ld | rd) & ((1 << n) - 1);
        while (bits > 0)
        {
            int pick = bits & -bits; // 注: x & -x
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; // 注: x & (x - 1)
        }
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    vector<vector<string>> res = soluter.solveNQueens(8);
    int idx = 1;
    for(auto vs : res)
    {
        cout << endl << "method " << (idx++) << ": " << endl;
        for(auto s : vs) cout << s << endl;
    }
    return 0;
}