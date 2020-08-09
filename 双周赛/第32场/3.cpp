/*
* @Author: wilson_t
* @Date:   2020-08-08 22:26:24
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 20:22:20
*/
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int res = 0;
        int leftCnt = 0;
        bool isRight = false;
        for(int i = 0; i < n; ++i) {
            if(s[i] == '(') {
                if(isRight) {
                    res++;
                    isRight = false;
                    if(leftCnt == 0) {
                        res++;
                    } else {
                        leftCnt--;
                    }
                }
                leftCnt += 1;
            } else {
                if(isRight) {
                    if(leftCnt == 0) {
                        res += 1;
                        leftCnt++;
                    }
                    leftCnt--;
                    isRight = false;
                } else {
                    isRight = true;
                }
            }
        }
        if(isRight) {
            res++;
            if(leftCnt == 0) {
                res++;
            } else {
                leftCnt--;
            }
        }
        if(leftCnt > 0) {
            res += leftCnt * 2;
        }
        return res;
    }
};