/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-06 14:11:13
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */

/****************************************************************
 * 题目[简单]：
 * 给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
 * 
 * 示例 1：
 * 输入: s1 = "abc", s2 = "bca"
 * 输出: true 
 * 
 * 示例 2：
 * 输入: s1 = "abc", s2 = "bad"
 * 输出: false
 * 
 * 说明：
 * 0 <= len(s1) <= 100
 * 0 <= len(s2) <= 100
 ***************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    static bool checkPermutation(const string& s1, const string& s2)
    {
        if(s1.size() != s2.size())
            return false;
        int numOfChars_1[128] = {0};
        int numOfChars_2[128] = {0};
        for(int i = 0; i < s1.size(); ++i)
        {
            numOfChars_1[s1[i]] +=1;
            numOfChars_2[s2[i]] +=1;
        }
        for(int i = 0; i < 128; ++i)
        {
            if(numOfChars_1[i] != numOfChars_2[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char * argv[])
{
    string s1 = "abcdefghijklmnopqrstuvwxyz";
    string s2 = "zyxwvutsrqponmlkjihgfedcba";
    if(Solution::checkPermutation(s1, s2))
    {
        cout << "s1 and s2 can be transformed to each other!" << endl;
    }
    else
    {
        cout << "can't be transformed to each other!" << endl;
    }
    return 0;
}