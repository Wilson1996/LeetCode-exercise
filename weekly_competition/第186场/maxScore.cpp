/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-04-26 10:32:33
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-04-26 10:40:58
*/
class Solution
{
public:
    int maxScore(string s)
    {
        int num0 = 0, num1 = 0;
        int score = 0;
        for(auto& c : s)
        {
            if(c == '1')
                ++num1;
        }
        if(s[0] == '0')
        {
            num0 += 1;
        }
        else
            num1 -= 1;
        score = num0 + num1;
        for(int i = 1; i < nums.size() - 1; ++i)
        {
            if(s[i] == '0')
                ++num0;
            else
                --num1;
            if(num0 + num1 > score)
                score = num0 + num1;
        }
        return score;
    }
};