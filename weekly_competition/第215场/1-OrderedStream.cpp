/*
* @Author: wilson_t
* @Date:   2020-11-15 21:11:53
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-11-15 21:11:59
*/
class OrderedStream {
    int n, ptr;
    vector<string> v;
public:
    OrderedStream(int _n) {
        n = _n;
        ptr = 1;
        v.resize(n + 1, "");
    }

    vector<string> insert(int id, string value) {
        v[id] = value;
        vector<string> res;
        while(ptr <= n && v[ptr] != "") {
            res.emplace_back(v[ptr]);
            ++ptr;
        }
        return res;
    }
};
