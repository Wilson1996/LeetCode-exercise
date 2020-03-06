/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-06 00:23:15
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */
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
