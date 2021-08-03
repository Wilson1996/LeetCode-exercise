/*
* @Author: wilson_t
* @Date:   2021-07-28 13:05:57
* @Last Modified by:   wilson_t
* @Last Modified time: 2021-07-28 13:06:44
*/
const int64 mod = 1'000'000'007;
struct hashFunc {
    size_t operator()(const vector<int>& v) const {
        int n = v.size();
        int64 code = 0;
        for(int i = 0; i < n; ++i) {
            code = (code * 256 + v[i]) % mod;
        }
        return code % mod;
    }
};

struct eqFunc {
    bool operator()(const vector<int>& v1, const vector<int>& v2) const {
        if(v1.size() != v2.size()) return false;
        int n = v1.size();
        for(int i = 0; i < n; ++i) {
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};

unordered_map<vector<int>, int, hashFunc, eqFunc> mp;