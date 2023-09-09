/*
* @Author: wilson_t
* @Date:   2020-10-11 19:31:10
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-11 19:31:16
*/
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        bool ok1 = true, ok2 = true;
        for(int i = 0, j = n - 1; i < j; ++i, --j) {
            if(a[i] != b[j]) {
                ok1 = false;
            }
            if(a[j] != b[i]) {
                ok2 = false;
            }
            if((!ok1) && (!ok2)) {
                if(j <= i) return true;
                int l = i, r = j;
                while(l < r) {
                    if(a[l] != a[r]) break;
                    ++l;
                    --r;
                }
                if(l >= r) return true;
                l = i, r = j;
                while(l < r) {
                    if(b[l] != b[r]) break;
                    ++l;
                    --r;
                }
                return l >= r;
            }
        }
        return true;
    }
};