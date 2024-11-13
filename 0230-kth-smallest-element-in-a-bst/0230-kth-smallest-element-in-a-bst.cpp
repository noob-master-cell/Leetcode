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
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){

            TreeNode * temp=q.front();
            q.pop();

            if(pq.size()<k){
                pq.push(temp->val);
            }

            else{

                if(temp->val < pq.top()){
                    pq.pop();
                    pq.push(temp->val);
                }
            }

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        return pq.top();
    }
};