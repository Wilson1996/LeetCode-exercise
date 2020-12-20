/*
* @Author: wilson_t
* @Date:   2020-12-20 18:13:06
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-12-20 18:13:47
*/
/*
给你一个字符串形式的电话号码 number 。number 由数字、空格 ' '、和破折号 '-' 组成。
请你按下述方式重新格式化电话号码。
首先，删除 所有的空格和破折号。
其次，将数组从左到右 每 3 个一组 分块，直到 剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
2 个数字：单个含 2 个数字的块。
3 个数字：单个含 3 个数字的块。
4 个数字：两个分别含 2 个数字的块。
最后用破折号将这些块连接起来。注意，重新格式化过程中 不应该 生成仅含 1 个数字的块，并且 最多 生成两个含 2 个数字的块。
返回格式化后的电话号码。

提示：
2 <= number.length <= 100
number 由数字和字符 '-' 及 ' ' 组成。
number 中至少含 2 个数字。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reformat-phone-number
*/
class Solution {
public:
    string reformatNumber(string number) {
        string num = "";
        for(char c : number) {
            if(c != ' ' && c != '-') num.push_back(c);
        }
        string res = "";
        int n = num.size();
        int i = 0;
        while(i < n) {
            if(n - i > 4) {
                res += num.substr(i, 3);
                res += "-";
                i += 3;
            } else if(n - i == 4) {
                res += num.substr(i, 2);
                res += "-";
                i += 2;
                res += num.substr(i, 2);
                i += 2;
            } else {
                res += num.substr(i, n - i);
                i = n;
            }
        }
        return res;
    }
};