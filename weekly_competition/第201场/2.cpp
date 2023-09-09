/*
* @Author: wilson_t
* @Date:   2020-08-09 20:23:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-09 20:24:16
*/
class Solution {
    int size[21];
public:
    char getBit(int n, int k) {
        if(n == 1) {
            return '0';
        } else if(n == 2) {
            return "011"[k - 1];
        }
        if(k == size[n - 1] + 1) return '1';
        else if(k <= size[n - 1]) {
            return getBit(n - 1, k);
        } else {
            char res = getBit(n - 1, 2 * size[n - 1] - k + 2);
            return res == '0' ? '1' : '0';
        }
    }
    char findKthBit(int n, int k) {
        size[1] = 1;
        for(int i = 2; i <= 20; ++i) {
            size[i] = size[i - 1] * 2 + 1;
        }
        return getBit(n, k);
    }
};