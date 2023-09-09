/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-19 10:54:35
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-19 11:20:39
*/
/*********************************************************
示例 1：

输入：s = "a0b1c2"
输出："0a1b2c"
解释："0a1b2c" 中任意两个相邻字符的类型都不同。 "a0b1c2", "0a1b2c", "0c2a1b" 也是满足题目要求的答案。
示例 2：

输入：s = "leetcode"
输出：""
解释："leetcode" 中只有字母，所以无法满足重新格式化的条件。
示例 3：

输入：s = "1229857369"
输出：""
解释："1229857369" 中只有数字，所以无法满足重新格式化的条件。
示例 4：

输入：s = "covid2019"
输出："c2o0v1i9d"
示例 5：

输入：s = "ab123"
输出："1a2b3"
*********************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution
{
public:
    static string reformat(string s)
    {
        string result;
        vector<char> figures;
        vector<char> digits;
        for(auto c : s)
        {
            if(c >= '0' && c <= '9')
                figures.push_back(c);
            else
                digits.push_back(c);
        }
        int _max = max(figures.size(), digits.size());
        int _min = min(figures.size(), digits.size());
        if(_max - _min > 1)
            return result;
        vector<char>* _long = &figures;
        vector<char>* _short = &digits;
        if(figures.size() < digits.size())
        {
            _long = &digits;
            _short = &figures;
        }
        int i = 0, j = 0;
        while(i < _max || j < _min)
        {
            result.push_back((*_long)[i]);
            if(j < _min) result.push_back((*_short)[j]);
            ++i;
            ++j;
        }
        return result;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution::reformat("covid2019") << endl;
    return 0;
}