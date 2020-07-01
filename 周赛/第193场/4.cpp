/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-14 09:39:08
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-14 22:52:23
*/
class TreeAncestor
{
private:
    vecotr<vector<int>> parent;

    int n;
public:
    TreeAncestor(int _n, vector<int>& _parent) : n(_n)
    {
        parent = vector<vector<int>>(n);
        for(int i = 1; i < n; ++i)
        {
            int node = i;
            while(node != -1)
            {
                parent[node].push_back(node);
                node = parent[node];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        return k > parent[node].size() ? -1 : parent[node][k];
    }
};

class TreeAncestor
{
private:
    typedef long long ll;
    vector<int> parent;
    unordered_map<ll, int> record;
    int n;
public:
    TreeAncestor(int _n, vector<int>& _parent) : n(_n), parent(_parent)
    {
    }

    int getKthAncestor(int node, int k)
    {
        if(node == 0) return k == 0 ? 0 : -1;
        if(k == 0) return node;
        if(record.count((ll(node)) << 32 | k) != 0) return record[(ll(node)) << 32 | k];
        int tmp = getKthAncestor(parent[node], k - 1);
        record[(ll(parent[node])) << 32 | (k - 1)] = tmp;
        return tmp;
    }
};
class TreeAncestor
{
private:
    vector<int> parent;
    vector<map<int, int>> record;
    int n;
public:
    TreeAncestor(int _n, vector<int>& _parent) : n(_n), parent(_parent)
    {
        record = vector<map<int, int>>(n);
    }

    int getKthAncestor(int node, int k)
    {
        if(node == 0) return k == 0 ? 0 : -1;
        if(k == 0) return node;
        if(record[node].find(k) != record[node].end()) return record[node][k];
        int tmp = getKthAncestor(parent[node], k - 1);
        record[node][k] = tmp;
        return tmp;
    }
};

class TreeAncestor
{
private:
    vector<int> parent;
    vector<map<int, int>> record;
    int n;
public:
    TreeAncestor(int _n, vector<int>& _parent) : n(_n), parent(_parent)
    {
        record = vector<map<int, int>>(n);
    }

    int getKthAncestor(int node, int k)
    {
        if(node == 0) return k == 0 ? 0 : -1;
        if(k == 0) return node;
        if(record[node].find(k) != record[node].end()) return record[node][k];
        else if(record[node].rbegin().first < k)
        {
            int t = getKthAncestor(record[node].rbegin().second, k - record[node].rbegin().first);
            record[node][k - record[node].rbegin().first] = t;
            return t;
        }
        int tmp = getKthAncestor(parent[node], k - 1);
        record[node][k] = tmp;
        return tmp;
    }
};

//from huang
class TreeAncestor
{
public:
    int f[22][50005];
    TreeAncestor(int n, vector<int>& p)
    {
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            f[0][i] = p[i - 1] + 1;
        }
        for (int i = 1; i < 18; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                f[i][j] = f[i - 1][f[i - 1][j]];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        node++;
        for (int i = 18; i >= 0; i--)
        {
            if (k > (1 << i))
            {
                k -= (1 << i);
                node = f[i][node];
            }
        }
        node = f[0][node];
        return node - 1;
    }
};