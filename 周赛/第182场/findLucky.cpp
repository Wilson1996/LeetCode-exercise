/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-29 11:16:38
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-29 11:20:19
*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
	static int findLucky(vector<int>& arr)
	{
		unordered_map<int, int> numSet;
		for(int x: arr)
		{
			numSet[x] += 1;
		}
		int luckyNum = -1;
		for(auto it = numSet.begin(); it != numSet.end(); ++it)
		{
			if(it->first == it->second && it->first > luckyNum)
				luckyNum = it->first;
		}
		return luckyNum;
	}
};

int main(int argc, char* argv[])
{
	vector<int> arr = {1,2,2,3,3,3};
	cout << Solution::findLucky(arr) << endl;
	return 0;
}