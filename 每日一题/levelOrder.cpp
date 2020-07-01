/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-13 00:15:27
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-13 10:51:40
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        if(root)
            Q.push(root);
        while(!Q.empty())
        {
            int size = Q.size();
            vector<int> level;
            for(int _ = 0; _ < size; ++_)
            {
                TreeNode* cur = Q.front();
                Q.pop();
                level.emplace_back(cur->val);
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            res.push_back(level);
        }
        return res;
    }
};