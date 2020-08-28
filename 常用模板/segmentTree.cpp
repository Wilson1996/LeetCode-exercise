/*
* @Author: wilson_t
* @Date:   2020-08-28 22:20:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-28 23:57:13
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = (1 << 20);
int tree[MAX_SIZE];

class ST {
private:
    int n;
    vector<int> arr;

    int _query(int cur, int l, int r, int start, int end) {
        if(start <= l && r <= end) return tree[cur];
        if(end < l || start > r) return 0;
        // printf("[%d, %d] = %d\n", l, r, cur);
        int mid = (l + r) / 2, left = 2 * cur, right = 2 * cur + 1;
        int sum = 0;
        sum += _query(left, l, mid, start, end);
        sum += _query(right, mid + 1, r, start, end);
        return sum;
    }
    void _add(int cur, int l, int r, int k, int ins) {
        if(l == r) {
            tree[cur] += ins;
            return;
        }
        int left = cur * 2, right = cur * 2 + 1, mid = (l + r) / 2;
        if(k <= mid) {
            _add(left, l, mid, k, ins);
        } else {
            _add(right, mid + 1, r, k, ins);
        }
        tree[cur] += ins;
    }
public:
    ST(vector<int>& v) {
        n = v.size();
        arr = v;
        memset(tree, 0, sizeof(int) * (2 * n + 5));
        build(v, 1, 0, n - 1);
        // for(int i = 0; i < 2 * n + 5; ++i) {
        //     cout << tree[i] << ", ";
        // }
        // cout << endl;
    }
    void build(vector<int>& v, int cur, int l, int r) {
        if(l == r) {
            tree[cur] = v[l];
            return;
        }
        int mid = (l + r) / 2, left = 2 * cur, right = 2 * cur + 1;
        build(v, left, l, mid);
        build(v, right, mid + 1, r);
        tree[cur] = tree[left] + tree[right];
    }

    void update(int k, int val) {
        _add(1, 0, n - 1, k, val - arr[k]);
        arr[k] = val;
    }

    int query(int l, int r) {
        return _query(1, 0, n - 1, l, r);
    }
};

int main(int argc, char* argv[]) {
    vector<int> v = {3, 4, 2, 1, 7, 8, 6, 5, 9};
    ST st(v);
    cout << st.query(0, 8) << endl;
    // cout << st.query(0, 2) << endl;
    st.update(0, 23);
    cout << st.query(0, 8) << endl;


    return 0;
}