/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-06-16 00:04:28
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-06-16 09:10:54
*/
/*********************************************************
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据
存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，
你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。

示例: 
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。
你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

说明: 不要使用类的成员/全局/静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
*********************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    vector<string> regexsplit(const string& input, const string& pattern)
    {
        regex re(pattern);
        sregex_token_iterator p(input.begin(), input.end(), re, -1);
        sregex_token_iterator end;
        vector<string> vec;
        while (p != end)
            vec.emplace_back(*p++);
        return vec;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if(root == NULL) return "";
        vector<string> nodes;
        unordered_map<TreeNode*, int> mp;
        nodes.resize((1 << 10) + 1, "null");
        queue<TreeNode*> Q;
        Q.push(root);
        nodes[1] = to_string(root->val);
        mp[root] = 1;
        int _size = 1;
        while(!Q.empty())
        {
            TreeNode* cur = Q.front();
            Q.pop();
            int idx = mp[cur];
            if(idx * 2 + 1 > nodes.size()) nodes.resize(idx * 4 + 1, "null");
            if(cur->left)
            {
                nodes[_size = idx * 2] = to_string(cur->left->val);
                Q.push(cur->left);
                mp[cur->left] = idx * 2;
            }
            if(cur->right)
            {
                nodes[_size = idx * 2 + 1] = to_string(cur->right->val);
                Q.push(cur->right);
                mp[cur->right] = idx * 2 + 1;
            }
        }
        string ser = nodes[1];
        for(int i = 2; i <= _size; ++i)
        {
            ser += "," + nodes[i];
        }
        cout << ser << endl;
        return ser;
    }
    TreeNode* helper(vector<string>& vs, int idx)
    {
        if(idx >= vs.size() || vs[idx] == "null") return nullptr;
        TreeNode* cur = new TreeNode(stoi(vs[idx]));
        cur->left = helper(vs, 2 * idx + 1);
        cur->right = helper(vs, 2 * idx + 2);
        return cur;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if(data == "") return NULL;
        vector<string> nodes = regexsplit(data, ",");
        return helper(nodes, 0);
    }
};
int main(int argc, char* argv[])
{
}