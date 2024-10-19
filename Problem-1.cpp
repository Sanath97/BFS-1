
// Time Complexity : O(n) where n is number of nodes in tree
// Space Complexity : O(d) d is diameter of the tree 
// Did this code successfully run on Leetcode : yes
// Any problem you faced while coding this : no
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> interm_res;
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                TreeNode* curr_node = q.front();
                q.pop();
                interm_res.push_back(curr_node->val);
                if(curr_node->left!=NULL)
                    q.push(curr_node->left);
                if(curr_node->right!=NULL)
                    q.push(curr_node->right);
            }
            res.push_back(interm_res);
            interm_res.clear();
        }
        return res;
    }
};