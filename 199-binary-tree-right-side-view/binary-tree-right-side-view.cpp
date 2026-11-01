/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(root == NULL)
        return res;
        q.push(root);
        while(!q.empty())
        {
            int lvl = q.size();
            for(int i=0;i<lvl;i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(i==0)
                res.push_back(t -> val);
                if(t -> right != NULL)
                q.push(t -> right);
                if(t -> left != NULL)
                q.push(t -> left);
            }
        }
        return res;
    }
};