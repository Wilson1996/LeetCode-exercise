/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-05 11:21:04
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-05 11:48:46
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;

class Solution
{
public:
	static void rightShift(string& s)
	{
		s.erase(s.size() - 1, 1);
	}
	static void plusOne(string& s)
	{
		int pos = s.size() - 1;
		int carry = 1;
		while(pos >= 0)
		{
			int bit_val = s[pos] - '0';
			s[pos] = bit_val ^ carry + '0';
			carry = bit_val & carry;
			--pos;
		}
		if(carry != 0)
			s.insert(0, 1, '1');
	}
	static int numSteps(string s)
	{
		int steps = 0;
		while(s.size() > 1)
		{
			if(s.back() == '1')
			{
				plusOne(s);
			}
			else
			{
				rightShift(s);
			}
			++steps;
		}
		return steps;
	}
};

int main(int argc, char* argv[])
{
	string s = "1";
	cout << Solution::numSteps(s) << endl;
	// Solution::rightShift(s);
	// cout << s << endl;
	// Solution::plusOne(s);
	// cout << s << endl;
	return 0;
}