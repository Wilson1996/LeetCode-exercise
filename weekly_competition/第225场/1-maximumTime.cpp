/*
* @Author: wilson_t
* @Date:   2021-01-24 14:03:44
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-01-24 14:06:29
*/
class Solution {
public:
    string maximumTime(string t) {
        if(t[0] == '?') {
            if(t[1] != '?' && t[1] >= '4') t[0] = '1';
            else t[0] = '2';
        }
        if(t[1] == '?') {
            if(t[0] == '2') t[1] = '3';
            else t[1] = '9';
        }
        if(t[3] == '?') t[3] = '5';
        if(t[4] == '?') t[4] = '9';
        return t;
    }
};