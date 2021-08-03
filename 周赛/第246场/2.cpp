/*
* @Author: wilson_t
* @Date:   2021-06-20 10:24:46
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-06-20 12:24:36
*/
class Solution {
public:
    int trans(string t) {
        int hour = (t[0] - '0') * 10 + t[1] - '0';
        int min = (t[3] - '0') * 10 + t[4] - '0';
        return hour * 60 + min;
    }
    int numberOfRounds(string startTime, string finishTime) {
        int start = trans(startTime), end = trans(finishTime);
        if(start >= end) {
            end += 24 * 60;
        }
        int res = end / 15 - (start + 14) / 15;
        return res;
    }
};