/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-09 17:56:35
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */

/****************************************************************
 * 题目[简单]：
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。如果你最多只允许
 * 完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 注意你不能在买入股票前卖出股票。
 * 
 * 示例 1:
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 * 
 * 示例 2:
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 动态规划思想
 ****************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) 
    {
        if(prices.size() <= 1)
            return 0;
        int buyDay, sellDay = 0;
        int min_price = prices[0];
        int max_profit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(max_profit < prices[i] - min_price)
            {
                max_profit = prices[i] - min_price;
                sellDay = i;
            }
            if(min_price > prices[i])
            {
                min_price = prices[i];
                buyDay = i;
            }
            // max_profit = max(max_profit, prices[i] - min_price);
            // min_price = min(min_price, prices[i]);
        }
        cout << "buyDay: " << buyDay+1 << " sellDay: " << sellDay+1 << endl;
        return max_profit;
    }
};

int main(int argc, char * argv[])
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << "max profit: " << Solution::maxProfit(prices) << endl;
    return 0;
}