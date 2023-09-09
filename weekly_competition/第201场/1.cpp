/*
* @Author: wilson_t
* @Date:   2020-08-09 20:22:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 20:23:57
*/
class Solution {
public:
    string makeGood(string s) {
        int  n = s.size();
        string res = "";
        bool isValid = true;
        while(isValid) {
            isValid = false;
            int i = 0;
            for(; i < n - 1; ++i) {
                if(abs(s[i] - s[i + 1]) == 32) {
                    ++i;
                    isValid = true;
                } else {
                    res.push_back(s[i]);
                }
            }
            if(i == n - 1) {
                res.push_back(s[n - 1]);
            }
            if(res == "")
                return "";
            s = res;
            // cout << s << endl;
            n = s.size();
            res = "";
        }
        return s;
    }
};