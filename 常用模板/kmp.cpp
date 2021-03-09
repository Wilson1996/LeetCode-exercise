#include<iostream>
#include<vector>

using namespace std;
vector<int> getNext(string pattern) {
    int k = -1; //匹配的前缀长度，-1代表长度为0
    vector<int> next(pattern.length(), -1);
    for(int i = 1; i < pattern.length(); i++) {
        while(k > -1 && pattern[k + 1] != pattern[i]) {
            k = next[k];
        }
        if(pattern[k + 1] == pattern[i]) {
            k = k + 1;
        }
        next[i] = k;
    }
    return next;
}

vector<int> KMP(string str, string pattern) {
    vector<int> next = getNext(pattern);
    int k = -1;
    vector<int> res;
    for(int i = 0; i < str.length(); i++) {
        while(k > -1 && pattern[k + 1] != str[i]) {
            k = next[k];
        }
        if(pattern[k + 1] == str[i]) {
            k = k + 1;
        }
        if(k == pattern.length() - 1) {
            res.push_back(i - pattern.length() + 1);
            k = -1;
        }
    }
    return res;
}

int main() {
    string str, pattern;
    cin >> str >> pattern;
    vector<int> res = KMP(str, pattern);
    if(res.empty()) {
        cout << -1 << endl;
    } else {
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
}


/*
有一个字符串。求除去字符串本身以外，这个字符串最大的公共前后缀的长度是多少？
例如，对于字符串ABABA而言，“ABA”即是它的前缀，也是它的后缀，且是最长的公共前后缀，因此最大的长度是3。
给定一个只包含大写字母的字符串s，返回除去字符串本身以外公共前后缀最大长度，如果没有任何一个公共前后缀满足要求，返回-1即可。
 */
class Solution {
public:
    int solve(string s) {
        int m = s.size();
        vector<int> fail(m, -1);
        for (int i = 1; i < m; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        return fail[m - 1] == -1 ? -1 : fail[m - 1] + 1;
    }
};