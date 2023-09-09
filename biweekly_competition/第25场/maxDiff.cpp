/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-02 22:47:26
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-02 23:25:52
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    static int maxDiff(int num)
    {
        int digits[9] = {0};
        int tmp = num;
        int index = 8;
        while(0 != tmp)
        {
            digits[index--] = tmp % 10;
            tmp /= 10;
        }
        ++index;
        int _max = num, _min = num;
        int markIndex = -1;
        for(int i = index; i <= 8; ++i)
        {
            if(digits[i] < 9 && markIndex == -1)
            {
                _max += (9 - digits[i]) * pow(10, 8 - i);
                markIndex = i;
            }
            else if(digits[i] == digits[markIndex])
            {
                _max += (9 - digits[i]) * pow(10, 8 - i);
            }
        }
        markIndex = -1;
        int _i = index;
        while((digits[_i] == 1 || digits[_i] == 0) && _i < 8)
        {
            ++_i;
        }
        if(_i == index)
            _min -= (digits[_i] - 1) * pow(10, 8 - _i);
        else
            _min -= (digits[_i] - 0) * pow(10, 8 - _i);
        for(int i = _i + 1; i <= 8; ++i)
        {
            if(digits[i] == digits[_i])
            {
                if(_i == index)
                    _min -= (digits[i] - 1) * pow(10, 8 - i);
                else
                    _min -= (digits[i] - 0) * pow(10, 8 - i);
            }
        }
        // if(digits[index] > 1)
        // {
        // 	_min -= (digits[index] - 1) * pow(10, 8 - index);
        // }
        // else
        // {
        // 	for(int i = index + 1; i <= 8; ++i)
        // 	{
        // 		if(digits[i] > 0 && markIndex == -1)
        // 		{
        // 			_min -= (digits[i] - 0) * pow(10, 8 - i);
        // 			markIndex = i;
        // 		}
        // 		else if(digits[i] == digits[markIndex])
        // 		{
        // 			_min -= (digits[i] - 0) * pow(10, 8 - i);
        // 		}
        // 	}
        // }
        cout << "max: " << _max << "\n" << "min: " << _min << endl;
        return _max - _min;
    }
};

int main(int argc, char* argv[])
{
    cout << Solution::maxDiff(1101057) << endl;
    return 0;
}