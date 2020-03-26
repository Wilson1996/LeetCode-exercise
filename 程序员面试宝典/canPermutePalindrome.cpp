/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-06 11:46:31
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-26 11:47:27
*/
/*********************************************************
* 题目[简单]：
给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
回文串不一定是字典当中的单词。
 
示例1：
输入："tactcoa"
输出：true（排列有"tacocat"、"atcocta"，等等）
*********************************************************/
class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        int numOfChars[128] = {0};
        for(int i = 0; i < s.size(); ++i)
        {
            numOfChars[s[i]] += 1;
        }
        int oddNum = 0;
        for(int i = 0; i < 128; ++i)
        {
            if(numOfChars[i] % 2 != 0)
            {
                if(oddNum == 0)
                    oddNum += 1;
                else
                    return false;
            }
        }
        return true;
    }
};