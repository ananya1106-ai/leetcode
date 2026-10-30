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
    int maxDepth(TreeNode* root) {
        queue <TreeNode*> q;
        if(root == NULL)
        return 0;
        q.push(root);
        int depth = 0;
        while(!q.empty())
        {
            int lvl = q.size();
            vector<int> temp;
            depth++;
            while(lvl--)
            {
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t -> val);
                if(t -> left != NULL)
                q.push(t -> left);
                if(t-> right != NULL)
                q.push(t->right);
            }
        }
        return depth;
    }
};