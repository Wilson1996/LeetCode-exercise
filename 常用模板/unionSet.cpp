class UnionSet {
    static const int N = 26;
    int parent[N];
public:
    //迭代
    int find(int x) {
        int son = x;
        while(parent[x] != x)
            x = parent[x];
        //路径压缩
        while(son != x) {
            int tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }
        return x;
    }
    //递归
    int find(int x) {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void join(int x, int y) {
        int root1 = find(x);
        int root2 = find(y);
        if(root1 != root2) {
            parent[root2] = root1;
        }
    }
};

class UF {
public:
    vector<int> fa;
    vector<int> sz;
    int n;
    int comp_cnt;

public:
    UF(int _n): n(_n), comp_cnt(_n), fa(_n), sz(_n, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int findset(int x) {
        return fa[x] == x ? x : fa[x] = findset(fa[x]);
    }

    void unite(int x, int y) {
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        fa[y] = x;
        sz[x] += sz[y];
        --comp_cnt;
    }

    bool findAndUnite(int x, int y) {
        int x0 = findset(x);
        int y0 = findset(y);
        if (x0 != y0) {
            unite(x0, y0);
            return true;
        }
        return false;
    }
};