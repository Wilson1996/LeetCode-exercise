/*
* @Author: wilson_t
* @Date:   2020-09-02 12:34:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-09-02 17:56:20
*/
#include <bits/stdc++.h>
using namespace std;

const int False = -1;
const int None = 0;
const int Sign = 1;
const int Int = 2;
const int Float = 3;
const int Science = 4;
const int Sci_Sign = 5;
const int Sci_Int = 6;
const int Dot = 7;
const int Space = 8;

class Solution {
public:
    int st = None;
    int getState(char c) {
        switch(st) {
            case None:
                if(c == ' ') return None;
                else if(c == '+' || c == '-') return Sign;
                else if(c >= '0' && c <= '9') return Int;
                else if(c == '.') return Dot;
                else return False;
            case Sign:
                if(c >= '0' && c <= '9') return Int;
                else if(c == '.') return Dot;
                else return False;
            case Int:
                if(c >= '0' && c <= '9') return Int;
                else if(c == '.') return Float;
                else if(c == 'E' || c == 'e') return Science;
                else if(c == ' ') return Space;
                else return False;
            case Float:
                if(c == 'E' || c == 'e') return Science;
                else if(c >= '0' && c <= '9') return Float;
                else if(c == ' ') return Space;
                else return False;
            case Science:
                if(c == '+' || c == '-') return Sci_Sign;
                else if(c >= '0' && c <= '9') return Sci_Int;
                else return False;
            case Sci_Sign:
                if(c >= '0' && c <= '9') return Sci_Int;
                else return False;
            case Sci_Int:
                if(c >= '0' && c <= '9') return Sci_Int;
                else if(c == ' ') return Space;
                else return False;
            case Dot:
                if(c >= '0' && c <= '9') return Float;
                else return False;
            case Space:
                if(c == ' ') return Space;
                else return False;
            default:
                return False;
        }
    }
    bool isNumber(string s) {
        for(auto c : s) {
            st = getState(c);
            if(st == False) return false;
        }
        return st == Float || st == Int || st == Sci_Int || st == Space;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    cout << solution.isNumber("1.") << endl;
    return 0;
}