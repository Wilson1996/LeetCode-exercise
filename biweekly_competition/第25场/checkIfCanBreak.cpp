/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-02 23:31:52
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-03 00:10:47
*/
#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    static bool checkIfCanBreak(string s1, string s2)
    {
        int ch_nums1[26] = {0};
        int ch_nums2[26] = {0};
        int flag[26] = {0};
        for(int i = 0; i < s1.length(); ++i)
        {
            ++ch_nums1[s1[i] - 'a'];
            ++ch_nums2[s2[i] - 'a'];
        }
        // for(int i = 0; i < 26; ++i)
        // {
        //     flag[i] = ch_nums1[i] - ch_nums2[i];
        //     cout << flag[i] << ", ";
        // }
        // cout << endl;
        int index = 0;
        while(flag[index] == 0)
            ++index;
        // cout << index << endl;
        bool isPositive = flag[index] > 0 ? true : false;
        int sum = 0;
        for(int i = index; i < 26; ++i)
        {
            sum += flag[i];
            if((isPositive && sum < 0) || (!isPositive && sum > 0))
                return false;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
	string s1 = "abc";
	string s2 = "xya";
	cout << Solution::checkIfCanBreak(s1, s2) << endl;
	return 0;
}