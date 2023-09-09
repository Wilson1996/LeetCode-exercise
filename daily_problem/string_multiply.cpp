/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-03-14 11:38:13
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-03-14 21:05:28
*/

/**************************************************************
* 题目[中等]：
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，
它们的乘积也表示为字符串形式。

* 示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

* 示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"

* 说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
***************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	static string multiply(string num1, string num2)
	{
		if(num1 == "0" || num2 == "0")
			return "0";
		int len_1 = num1.length();
		int len_2 = num2.length();
		string result(len_1 + len_2, 0);
		for(int i = len_1 - 1; i >= 0; --i)
		{
			int carry = 0;
			for(int j = len_2 - 1; j >= 0; --j)
			{
				result[i + j + 1] += ((num1[i] - '0') * (num2[j] - '0') + carry);
				if(result[i + j + 1] > 9)
				{
					carry = result[i + j + 1] / 10;
					result[i + j + 1] %= 10;
				}
				else
					carry = 0;
			}
			if(carry != 0)
				result[i] += carry;
		}
		int delete_size = 0;
		for(int i = 0; i < result.size() - 1; ++i)
		{
			if(result[i] != 0)
				break;
			++delete_size;
		}
		result.erase(0, delete_size);
		for(int i = 0; i < result.size(); ++i)
		{
			result[i] += '0';
		}
		return result;
	}
};

int main(int argc, char* argv[])
{
	string num1 = "12345678";
	string num2 = "98765432";
	cout << Solution::multiply(num1, num2) << endl;
	return 0;
}