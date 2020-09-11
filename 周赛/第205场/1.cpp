/*
* @Author: wilson_t
* @Date:   2020-09-06 12:49:05
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-11 17:00:19
*/
class Solution {
public:
    string modifyString(string s) {
        string res = "";
        res.push_back('#');
        res.append(s);
        res.push_back('#');
        int n = res.size();
        for(int i = 1; i < n - 1; ++i) {
            if(res[i] == '?') {
                for(char j = 'a'; j <= 'z'; ++j) {
                    if(j != res[i - 1] && j != res[i + 1]) {
                        res[i] = j;
                        break;
                    }
                }
            }
        }
        return res.substr(1, s.size());
    }
};