/*
* @Author: wilson_t(Wilson.T@sjtu.edu.cn)
* @Date:   2020-05-22 09:45:03
* @Last Modified by:   wilson_t
* @Last Modified time: 2020-05-22 09:45:11
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* recoverFromPreorder(string S)
    {
        vector<int> preorder;
        vector<int> depths;
        depths.emplace_back(0);
        int state = 0;
        int tmp = 0;
        int depth = 0;
        for(auto c : S)
        {
            if(state == 0)  //数
            {
                if(c == '-')
                {
                    preorder.emplace_back(tmp);
                    tmp = 0;
                    state = 1;
                    depth = 1;
                }
                else
                {
                    tmp = tmp * 10 + c - '0';
                }
            }
            else
            {
                if(c == '-')
                {
                    ++depth;
                }
                else
                {
                    depths.emplace_back(depth);
                    depth = 0;
                    state = 0;
                    tmp = c - '0';
                }
            }
        }
        preorder.emplace_back(tmp);
        for(auto& x : preorder) cout << x << ", ";
        cout << endl;
        for(auto& x : depths) cout << x << ", ";
        cout << endl;
        return NULL;
    }
};