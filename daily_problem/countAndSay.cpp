/*
* @Author: wilson_t
* @Date:   2020-10-06 19:19:22
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-10-06 19:20:18
*/
/*********************************************************
* 题目[简单]:
给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。
注意：整数序列中的每一项将表示为一个字符串。
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1
描述前一项，这个数是 1 即 “一个 1 ”，记作 11
描述前一项，这个数是 11 即 “两个 1 ” ，记作 21
描述前一项，这个数是 21 即 “一个 2 一个 1 ” ，记作 1211
描述前一项，这个数是 1211 即 “一个 1 一个 2 两个 1 ” ，记作 111221

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
*********************************************************/
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        else if(n == 2) return "11";
        else if(n == 3) return "21";
        else if(n == 4) return "1211";
        else if(n == 5) return "111221";
        string slast = "111221", sn = "";
        for(int i = 5; i < n; ++i) {
            sn = "";
            int sz = slast.size(), cnt = 1;
            char alpha = slast[0];
            for(int j = 1; j < sz; ++j) {
                if(slast[j] != alpha) {
                    sn += to_string(cnt);
                    sn.push_back(alpha);
                    cnt = 1;
                    alpha = slast[j];
                } else {
                    cnt++;
                }
            }
            sn += to_string(cnt);
            sn.push_back(alpha);
            slast = sn;
        }
        return slast;
    }
};