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
    int solve(TreeNode* root, int& ans)
    {
        if(root == NULL)
            return 0;
        int ls=solve(root->left, ans);
        ls = max(0, ls);
        
        int rs=solve(root->right, ans);
        rs = max(0, rs);
        
        ans=max(ans, ls+rs+root->val);
        
        return root->val + max(ls, rs);
        
    }
    int maxPathSum(TreeNode* root) 
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};