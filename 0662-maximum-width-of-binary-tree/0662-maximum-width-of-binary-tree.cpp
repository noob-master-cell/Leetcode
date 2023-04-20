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
    int widthOfBinaryTree(TreeNode* root) 
    {
        int width=0;
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            int s = q.size();
            int min = q.front().second;
            int first, last;
            for(int i=0; i<s; i++)
            {
                int itr =q.front().second-min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)
                    first=itr;
                if(i==s-1)
                    last = itr;
                if(node->left)
                    q.push({node->left, (long long)2*itr+1});
                if(node->right)
                    q.push({node->right, (long long)2*itr+2});                    
            }
            width = max(width, abs(last-first+1));
        }
        return width;
    }
};