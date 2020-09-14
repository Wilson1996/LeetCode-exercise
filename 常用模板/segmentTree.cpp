/*
* @Author: wilson_t
* @Date:   2020-08-28 22:20:43
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-08-31 11:09:29
*/

#include <bits/stdc++.h>
using namespace std;

// const int MAX_SIZE = (1 << 20);
// int tree[MAX_SIZE];

// class ST {
// private:
//     int n;
//     vector<int> arr;

//     int _query(int cur, int l, int r, int start, int end) {
//         if(start <= l && r <= end) return tree[cur];
//         if(end < l || start > r) return 0;
//         // printf("[%d, %d] = %d\n", l, r, cur);
//         int mid = (l + r) / 2, left = 2 * cur, right = 2 * cur + 1;
//         int sum = 0;
//         sum += _query(left, l, mid, start, end);
//         sum += _query(right, mid + 1, r, start, end);
//         return sum;
//     }
//     void _add(int cur, int l, int r, int k, int ins) {
//         if(l == r) {
//             tree[cur] += ins;
//             return;
//         }
//         int left = cur * 2, right = cur * 2 + 1, mid = (l + r) / 2;
//         if(k <= mid) {
//             _add(left, l, mid, k, ins);
//         } else {
//             _add(right, mid + 1, r, k, ins);
//         }
//         tree[cur] += ins;
//     }
// public:
//     ST(vector<int>& v) {
//         n = v.size();
//         arr = v;
//         memset(tree, 0, sizeof(int) * (2 * n + 5));
//         build(v, 1, 0, n - 1);
//         // for(int i = 0; i < 2 * n + 5; ++i) {
//         //     cout << tree[i] << ", ";
//         // }
//         // cout << endl;
//     }
//     void build(vector<int>& v, int cur, int l, int r) {
//         if(l == r) {
//             tree[cur] = v[l];
//             return;
//         }
//         int mid = (l + r) / 2, left = 2 * cur, right = 2 * cur + 1;
//         build(v, left, l, mid);
//         build(v, right, mid + 1, r);
//         tree[cur] = tree[left] + tree[right];
//     }

//     void update(int k, int val) {
//         _add(1, 0, n - 1, k, val - arr[k]);
//         arr[k] = val;
//     }

//     int query(int l, int r) {
//         return _query(1, 0, n - 1, l, r);
//     }
// };

namespace TW {
template<typename T>
class Sum {
public:
    const T None = 0;
    T operator()(T a, T b) {
        return a + b;
    }
};

template<typename T, typename Func = Sum<T>>
class ST {
private:
    const static int MAX_SIZE = (1 << 20);
    int n;
    vector<T> arr;
    T tree[MAX_SIZE];
    Func func;

    T _query(int cur, int l, int r, int start, int end) {
        if(start <= l && r <= end) return tree[cur];
        if(end < l || start > r) return func.None;
        int mid = (l + r) / 2, left = 2 * cur, right = 2 * cur + 1;
        return func(_query(left, l, mid, start, end), _query(right, mid + 1, r, start, end));
    }
    void _add(int cur, int l, int r, int k, T ins) {
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
        tree[cur] = func(tree[left], tree[right]);
    }
public:
    ST(vector<T>& v) {
        n = v.size();
        arr = v;
        memset(tree, 0, sizeof(int) * (2 * n + 5));
        build(v, 1, 0, n - 1);
    }
    void build(vector<T>& v, int cur, int l, int r) {
        if(l == r) {
            tree[cur] = v[l];
            return;
        }
        int mid = (l + r) / 2, left = 2 * cur, right = 2 * cur + 1;
        build(v, left, l, mid);
        build(v, right, mid + 1, r);
        tree[cur] = func(tree[left], tree[right]);
    }

    void update(int k, T val) {
        _add(1, 0, n - 1, k, val - arr[k]);
        arr[k] = val;
    }

    int query(int l, int r) {	// []
        return _query(1, 0, n - 1, l, r);
    }
};
}

template<typename T>
class Min {
public:
    const T None = 1e9;
    T operator()(T a, T b) {
        return a <= b ? a : b;
    }
};

template<typename T>
class Max {
public:
    const T None = -1e9;
    T operator()(T a, T b) {
        return a >= b ? a : b;
    }
};

template<typename T>
class Xor {
public:
    const T None = 0;
    T operator()(T a, T b) {
        return a ^ b;
    }
};

template<typename T>
class And {
public:
    const T None = (~0);
    T operator()(T a, T b) {
        return a & b;
    }
};

template<typename T>
class Or {
public:
    const T None = 0;
    T operator()(T a, T b) {
        return a | b;
    }
};

template<typename T>
class Multi {
public:
    const T None = 1;
    T operator()(T a, T b) {
        return a * b;
    }
};

int main(int argc, char* argv[]) {	
    vector<long long> v = {3,4,2,1,7,8,6,5,9,10};
    TW::ST<long long, Max<long long>>* st = new TW::ST<long long, Max<long long>>(v);
    // ST st(v);
    cout << st->query(0, 9) << endl;
    // cout << st.query(0, 2) << endl;
    st->update(0, 100);
    cout << st->query(0, 1) << endl;

    delete st;
    return 0;
}