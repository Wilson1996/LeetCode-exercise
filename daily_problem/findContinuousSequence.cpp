/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-06 00:23:15
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */

/****************************************************************
 * 题目[简单]:
 * 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
 * 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
 * 
 * 示例 1：
 * 输入：target = 9
 * 输出：[[2,3,4],[4,5]]
 * 
 * 示例 2：
 * 输入：target = 15
 * 输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 * 
 * 限制：
 * 1 <= target <= 10^5
 ****************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> findContinuousSequence(int target) 
    {
        vector<vector<int>> result;
        vector<int> sequence;
        int sum = 0;
        //窗口滑动
        for(int i = 1; i <= target/2 + 2; )
        {
            if(sum == target)
            {
                // cout << "****************"<<endl;
                result.push_back(sequence);
                sequence.push_back(i);
                sum += i;
                ++i;
            }
            else if(sum < target)
            {
                sum += i;
                sequence.push_back(i);
                ++i;
            }
            else
            {
                sum -= sequence.front();
                // cout << "sum: " << sum << endl; 
                sequence.erase(sequence.begin());
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> result = Solution::findContinuousSequence(15);
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
    return 0;
}
