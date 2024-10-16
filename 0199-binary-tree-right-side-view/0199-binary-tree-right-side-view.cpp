class Solution {
public:
    
    void solve(TreeNode* node, vector<int>& ans, int level)
    {
        if(node == NULL)
            return;
        if(ans.size()==level)
            ans.push_back(node->val);
        
        solve(node->right, ans, level+1);
        solve(node->left, ans, level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(root==NULL)
            return ans;
        int level = 0;
        solve(root, ans, level);
        return ans;
    }
};