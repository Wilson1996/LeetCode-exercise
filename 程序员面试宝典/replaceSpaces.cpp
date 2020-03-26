/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-26 11:37:55
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-26 11:38:38
*/
/*********************************************************
URL化。编写一种方法，将字符串中的空格全部替换为%20。
假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。
（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

示例1:
 输入："Mr John Smith    ", 13
 输出："Mr%20John%20Smith"

示例2:
 输入："               ", 5
 输出："%20%20%20%20%20"

提示：
字符串长度在[0, 500000]范围内。
*********************************************************/
class Solution
{
public:
    string replaceSpaces(string S, int length)
    {
        string result;
        for(int i = 0; i < length; ++i)
        {
            if(S[i] == ' ')
                result.append("%20");
            else
                result.push_back(S[i]);
        }
        return result;
    }
};