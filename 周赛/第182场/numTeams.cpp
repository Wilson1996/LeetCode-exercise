/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-29 11:22:39
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-29 11:29:05
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
	static int numTeams(vector<int>& rating)
	{
		int result = 0;
		for(int i = 0; i < rating.size(); ++i)
		{
			for(int j = i+1; j < rating.size(); ++j)
			{
				for(int k = j + 1; k < rating.size(); ++k)
				{
					if((rating[i] < rating[j] && rating[j] < rating[k]) 
						|| (rating[i] > rating[j] && rating[j] > rating[k]))
						++result;
				}
			}
		}
		return result;
	}
};

int main(int argc, char* argv[])
{
	vector<int> rating = {1,2,3,4};
	cout << Solution::numTeams(rating) << endl;
	return 0;
}