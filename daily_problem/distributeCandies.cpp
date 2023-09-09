/*
* @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-06 12:09:51
* @Last Modified by:   Williss.T
* @Last Modified time: 2020-03-06 12:25:41
*/

/******************************************************************************
 * 题目[简单]:
 * 排排坐，分糖果
 * 我们买了一些糖果 candies，打算把它们分给排好队的 n = num_people 个小朋友。
 * 给第一个小朋友 1 颗糖果，第二个小朋友 2 颗，依此类推，直到给最后一个小朋友 n 颗糖果。
 * 然后，我们再回到队伍的起点，给第一个小朋友 n + 1 颗糖果，第二个小朋友 n + 2 颗，
 * 依此类推，直到给最后一个小朋友 2 * n 颗糖果。重复上述过程（每次都比上一次多给出一颗糖果，
 * 当到达队伍终点后再次从队伍起点开始），直到我们分完所有的糖果。注意，就算我们手中的剩下糖
 * 果数不够（不比前一次发出的糖果多），这些糖果也会全部发给当前的小朋友。返回一个长度为 
 * num_people、元素之和为 candies 的数组，以表示糖果的最终分发情况（即 ans[i] 表示第 i 个小朋友分到的糖果数）。
 * 
 * 提示：
 * 1 <= candies <= 10^9
 * 1 <= num_people <= 1000
 ******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> distributeCandies(int candies, int num_people) 
    {
        int Candies2give = 1;
        int iter = 0;
        vector<int> numOfCandies(num_people, 0);
        while(candies > 0)
        {
            if(candies < Candies2give)
            {
                numOfCandies[iter] += candies;
                candies = 0;
            }
            else
            {
                numOfCandies[iter] += Candies2give;
                candies -= Candies2give;
                ++Candies2give;
            }
            ++iter;
            if(iter == num_people)
                iter = 0;
        }
        return numOfCandies;
    }
};

int main(int argc, char *argv[])
{
	vector<int> result = Solution::distributeCandies(90, 10);
	for(int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ", ";
	}
	cout << endl;
}