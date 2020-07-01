/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-17 11:53:41
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-17 15:40:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool mycmp(const string& a, const string& b)
{
    return a.size() < b.size();
}
class Solution
{
public:
    string arrangeWords(string text)
    {
        vector<string> VS;
        string tmp;
        string res;
        for(int i = 0; i < text.size(); ++i)
        {
            if(text[i] == ' ')
            {
                VS.emplace_back(tmp);
                tmp.clear();
            }
            else
            {
                tmp.push_back(text[i] | 32);
            }
        }
        VS.emplace_back(tmp);
        stable_sort(VS.begin(), VS.end(), mycmp);
        VS[0][0] &= ~32;
        res.append(VS[0]);
        for(int i = 1; i < VS.size(); ++i)
        {
            res.append(" " + VS[i]);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    string text = "Leetcode is cool";
    cout << soluter.arrangeWords(text) << endl;
    return 0;
}