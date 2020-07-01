/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-6 14:18:40
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-13 18:56:18
*/

/****************************************************************
 * 题目[简单]:
 * 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。
 *
 * 示例 1：
 * 输入: s = "leetcode"
 * 输出: false
 *
 * 示例 2：
 * 输入: s = "abc"
 * 输出: true
 *
 * 限制：
 * 0 <= len(s) <= 100
 * 如果你不使用额外的数据结构，会很加分。
****************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    static bool isUnique(const string& astr)
    {
        //hash 思想
        int numOfChars[128] = {0};
        for(int i = 0; i < astr.size(); ++i)
        {
            if(numOfChars[astr[i]] > 0)
                return false;
            numOfChars[astr[i]] += 1;
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    if(Solution::isUnique(s1))
    {
        cout << "chars of the string are unique" << endl;
    }
    else
    {
        cout << "chars of the string are not unique" << endl;
    }
    return 0;
}