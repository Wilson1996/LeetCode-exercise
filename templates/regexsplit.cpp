/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-12 23:34:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-12 23:34:37
*/
vector<string> regexsplit(const string& input, const string& pattern)
{
    regex re(pattern);
    sregex_token_iterator p(input.begin(), input.end(), re, -1);
    sregex_token_iterator end;
    vector<string> vec;
    while (p != end)
        vec.emplace_back(*p++);
    return vec;
}