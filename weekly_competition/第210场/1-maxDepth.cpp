/*
* @Author: wilson_t
* @Date:   2020-10-11 18:58:11
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-11 18:58:17
*/
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, res = 0;
        for(char c : s) {
            if(c == '(') {
                depth++;
                res = max(res, depth);
            } else if(c == ')') depth--;
        }
        return res;
    }
};