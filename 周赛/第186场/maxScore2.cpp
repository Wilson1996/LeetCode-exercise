/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-26 10:46:24
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-02-06 00:55:11
*/
/*********************************************************
几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。
每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。
你的点数就是你拿到手中的所有卡牌的点数之和。
给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。

示例 1：
输入：cardPoints = [1,2,3,4,5,6,1], k = 3
输出：12
解释：第一次行动，不管拿哪张牌，你的点数总是 1 。
但是，先拿最右边的卡牌将会最大化你的可获得点数。最优策略是拿右边的三张牌，最终点数为 1 + 6 + 5 = 12 。
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), res, sum;
        res = sum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
        for(int i = k - 1; i >= 0; --i) {
            sum = sum - cardPoints[i] + cardPoints[n + i - k];
            res = max(res, sum);
        }
        return res;
    }
};

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//         int len = cardPoints.size();
//         int result = 0;
//         deque<int> L;
//         deque<int> R;
//         int sumL = 0, sumR = 0;
//         for(int i = 0; i < k; ++i) {
//             L.push_back(cardPoints[i]);
//             sumL += cardPoints[i];
//             R.push_back(cardPoints[len - 1 - i]);
//             sumR += cardPoints[len - 1 - i];
//         }
//         for(int i = 0; i < k; ++i) {
//             if(sumL >= sumR) {
//                 result += L.front();
//                 sumL -= L.front();
//                 L.pop_front();
//                 sumR -= R.back();
//                 R.pop_back();
//             } else {
//                 result += R.front();
//                 sumR -= R.front();
//                 R.pop_front();
//                 sumL -= L.back();
//                 L.pop_back();
//             }
//         }
//         return result;
//     }
// };

int main(int argc, char* argv[]) {
    vector<int> cardPoints = {1, 79, 80, 1, 1, 1, 200, 1};
    Solution soluter;
    cout << soluter.maxScore(cardPoints, 3) << endl;
    return 0;
}