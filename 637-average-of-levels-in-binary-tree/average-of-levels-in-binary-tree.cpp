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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(!q.empty())
        {
            double sum = 0.0;
            int lvl = q.size();
            int total = lvl;
            while(lvl--)
            {
                TreeNode* t = q.front();
                q.pop();
                sum+= t-> val;
                if(t->left != NULL)
                q.push(t -> left);
                if(t->right != NULL)
                q.push(t->right);
            }
            double avg = sum/total;
            ans.push_back(avg);
        }
        return ans;
    }
};