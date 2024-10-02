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

     int solve(TreeNode*root,int&ans){
        if(root==NULL){
            return -1;
        }
           
            int left=solve(root->left,ans);
            int right=solve(root->right,ans);
            
            int got_ans=left+right+root->val;
            int one_side=max(left,right)+root->val;
            int no_ans=root->val;
            
            ans=max({ans,got_ans,one_side,no_ans});
            
           return max(one_side,no_ans);
        

     }
     
    int maxPathSum(TreeNode* root) {
        
int ans=INT_MIN;
         solve(root,ans);
        return ans;

    }
};