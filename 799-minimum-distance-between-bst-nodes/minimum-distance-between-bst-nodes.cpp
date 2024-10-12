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

void solve(TreeNode* root,int &ans,int &prev){
    if(!root){
        return;
    }

    solve(root->left,ans,prev);
    if(prev==INT_MIN){
        prev=root->val;
    }
   else{ ans= min(ans,root->val-prev);
   }
    prev=root->val;

    solve(root->right,ans,prev);
}
    int minDiffInBST(TreeNode* root) {
        int prev=INT_MIN;
        int ans=INT_MAX;
        solve(root,ans,prev);
        return ans; 
    }
};