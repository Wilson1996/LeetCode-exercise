/*
* @Author: wilson_t
* @Date:   2021-06-20 10:23:51
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-20 12:24:25
*/
class Solution {
public:
    string largestOddNumber(string num) {
        string res = "";
        int n = num.size();
        for(int i = n - 1; i >= 0; --i) {
            if((num[i] - '0') & 1) {
                int j = i;
                while(j >= 0) {
                    res.push_back(num[j--]);
                }
                reverse(res.begin(), res.end());
                return res;
            }
        }
        return res;
    }
};