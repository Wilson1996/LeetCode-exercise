using pii = pair<int, int>;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        int n = v.size();
        vector<pii> a;
        for(auto& vv : v) {
            a.emplace_back(vv[0], vv[1]);
        }
        sort(a.begin(), a.end(), [&](const auto & lhs, const auto & rhs) {
            if(lhs.first != rhs.first) return lhs.first < rhs.first;
            return lhs.second > rhs.second;
        });
        int res = 0;
        int mx = a[n - 1].second;
        for(int i = n - 2; i >= 0; --i) {
            if(a[i].second < mx) res++;
            mx = max(mx, a[i].second);
        }
        return res;
    }
};