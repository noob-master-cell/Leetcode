/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool findTarget(TreeNode *root, int k)
        {
            unordered_set<int> s;
            bool ans = false;
            find(root, k, s, ans);
            return ans;
        }
        void find(TreeNode *root, int k, unordered_set<int> &s, bool &ans)
        {
            if (root == NULL)
                return;

            if (s.count(k - root->val))
            {
                ans = true;
                return;
            }
            s.insert(root->val);
            find(root->left, k, s, ans);
            find(root->right, k, s, ans);
        }
};