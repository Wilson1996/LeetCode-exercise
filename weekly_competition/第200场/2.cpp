/*
* @Author: wilson_t
* @Date:   2020-08-03 00:31:12
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-03 00:31:56
*/
/*********************************************************
给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。
每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0] 与 arr[1] 的大小，
较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。

返回赢得比赛的整数。
题目数据 保证 游戏存在赢家。
*********************************************************/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        queue<int> q;
        int maxNum = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[i] > maxNum) maxNum = arr[i];
            q.push(arr[i]);
        }
        if(k >= n) {
            return maxNum;
        }
        int priot = q.front();
        q.pop();
        int cntWin = 0;
        for(int j = 0; j <= n; ++j) {
            int a = q.front();
            q.pop();
            if(a > priot) {
                q.push(priot);
                priot = a;
                cntWin = 1;
                if(cntWin >= k) {
                    return priot;
                }
            } else {
                ++cntWin;
                if(cntWin >= k) {
                    return priot;
                }
                q.push(a);
            }
        }
        return priot;
    }
};