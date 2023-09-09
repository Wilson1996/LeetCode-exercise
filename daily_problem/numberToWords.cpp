/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-06 16:52:21
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-06 18:33:22
*/
/*********************************************************
* 题目[困难]：
将非负整数转换为其对应的英文表示。可以保证给定输入小于 231 - 1 。

示例 1:
输入: 123
输出: "One Hundred Twenty Three"

示例 2:
输入: 12345
输出: "Twelve Thousand Three Hundred Forty Five"

示例 3:
输入: 1234567
输出: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

示例 4:
输入: 1234567891
输出: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*********************************************************/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, string> mp1 =
    {
        {0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"},
        {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}, {10, "Ten"},
        {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, {14, "Fourteen"}, {15, "Fifteen"},
        {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}
    };
    unordered_map<int, string> mp2 =
    {
        {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, {50, "Fifty"}, {60, "Sixty"},
        {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}
    };
    vector<string> unit = {"", " Thousand", " Million", " Billion"};
    string getWords(int num)
    {
        if(num < 20)
        {
            return mp1[num];
        }
        else if(num < 100)
        {
            int tmp = num % 10;
            return tmp == 0 ? mp2[num - tmp] : mp2[num - tmp] + " " + mp1[tmp];
        }
        else if(num < 1000)
        {
            int tmp = num % 100;
            return tmp > 0 ? mp1[num / 100] + " Hundred " + getWords(num % 100) : mp1[num / 100] + " Hundred";
        }
        return "";
    }
    string numberToWords(int num)
    {
        if(num == 0) return "Zero";
        string res;
        stack<int> sk;
        while(num != 0)
        {
            sk.push(num % 1000);
            num /= 1000;
        }
        int _size = sk.size();
        while(!sk.empty())
        {
            string tmp = getWords(sk.top());
            sk.pop();
            if(tmp != "")
            {
                if(_size == sk.size() + 1)
                    res += tmp + unit[sk.size()];
                else
                    res += " " + tmp + unit[sk.size()];
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution soluter;
    cout << soluter.numberToWords(1000000001) << endl;
    cout << soluter.numberToWords(0) << endl;
    cout << soluter.numberToWords(10000) << endl;
    cout << soluter.numberToWords(1000000) << endl;

    return 0;
}