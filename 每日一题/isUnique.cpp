/*
 * @Descripttion: 
 * @version: 
 * @Author: WillissTaan(Wilson.T@sjtu.edu.cn)
 * @Date: 2020-03-06 14:18:40
 * @Last Modified by: WillissTaan
 * @Last Modified Time: Do not edit
 */
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static bool isUnique(const string& astr) 
    {
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

int main(int argc, char * argv[])
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