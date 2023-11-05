// 树状数组模板（维护前缀最大值）
#include <vector>
#include <cstdlib>
#include <climits>

class BIT {
    std::vector<long long> tree;
public:
    BIT(int n) : tree(n, LLONG_MIN) {}

    void update(int i, long long val) {
        while (i < tree.size()) {
            tree[i] = std::max(tree[i], val);
            i += i & -i;
        }
    }

    long long pre_max(int i) {
        long long res = LLONG_MIN;
        while (i > 0) {
            res = std::max(res, tree[i]);
            i &= i - 1;
        }
        return res;
    }
};
