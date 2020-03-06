/*
* @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-06 12:09:51
* @Last Modified by:   Williss.T
* @Last Modified time: 2020-03-06 12:25:41
*/

/*
 * @ 难易程度：简单
 */

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