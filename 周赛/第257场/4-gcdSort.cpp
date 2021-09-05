int fa[100005];
int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) {
        if(fx < fy) swap(fx, fy);
        fa[fy] = fx;
        return true;
    }
    return false;
}

bool connected(int x, int y) {
    return find(x) == find(y);
}

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        unordered_map<int, vector<int> > prime;
        iota(fa, fa + 100005, 0);
        // for(int x: nums) {
        unordered_set<int> seen;
        for(int i = 0; i < n; ++i) {
            // mp[x]++;
            int x = nums[i];
            mp[x]++;
            if(seen.count(x)) continue;
            seen.insert(x);
            int now = x;
            for(int i = 2; i * i <= x; ++i) {
                if(x % i == 0) {
                    while(x % i == 0) {
                        x /= i;
                    }
                    for(int v : prime[i]) {
                        merge(now, v);
                        break;
                    }
                    prime[i].push_back(now);
                }
            }
            if(x > 1) {
                for(int v : prime[x]) {
                    merge(now, v);
                }
                prime[x].push_back(now);
            }
        }
        for(int i = 0; i < n; ++i) {
            if(mp.begin()->first == nums[i]) {
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                continue;
            }
            int x = mp.begin()->first;
            if(!connected(x, nums[i])) return false;
            mp[x]--;
            if(mp[x] == 0) mp.erase(x);
        }
        return true;
    }
};

/*
[8,9,4,2,3]
true
*/