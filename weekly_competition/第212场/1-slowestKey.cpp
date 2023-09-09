/*
* @Author: wilson_t
* @Date:   2020-10-27 12:31:53
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-27 12:31:59
*/
class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int n = releaseTimes.size(), most = releaseTimes[0];
        char res = keysPressed[0];
        for(int i = 1; i < n; ++i) {
            int t = releaseTimes[i] - releaseTimes[i - 1];
            if(t > most) {
                most = t;
                res = keysPressed[i];
            } else if(t == most) {
                res = max(res, keysPressed[i]);
            }
        }
        return res;
    }
};