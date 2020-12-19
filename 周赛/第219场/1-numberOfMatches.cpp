/*
* @Author: wilson_t
* @Date:   2020-12-13 15:38:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-13 15:39:07
*/
//淘汰赛的比赛轮次
class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0, now;
        while(n > 1) {
            if(n & 1) {
                now = (n - 1) / 2 + 1;
                res += (n - 1) / 2;
            } else {
                now = n / 2;
                res += n / 2;
            }
            n = now;
        }
        return res;
    }
};