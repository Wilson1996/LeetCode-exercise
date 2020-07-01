class UnionSet
{
    static const int N = 26;
    int parent[N];
public:
    //迭代
    int find(int x)
    {
        int son = x;
        while(parent[x] != x)
            x = parent[x];
        //路径压缩
        while(son != x)
        {
            int tmp = parent[son];
            parent[son] = x;
            son = tmp;
        }
        return x;
    }
    //递归
    int find(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void join(int x, int y)
    {
        int root1 = find(x);
        int root2 = find(y);
        if(root1 != root2)
        {
            parent[root2] = root1;
        }
    }
};