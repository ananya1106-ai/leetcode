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
    int minDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL)
        return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            depth++;
            int lvl = q.size();
            while(lvl--)
            {
                TreeNode* t = q.front();
                q.pop();
                // check leaf node
                if(t -> left == NULL && t -> right == NULL)
                return depth;
                if(t -> left != NULL)
                q.push(t -> left);
                if(t -> right != NULL)
                q.push(t -> right);
            }
        }
        return depth;
    }
};