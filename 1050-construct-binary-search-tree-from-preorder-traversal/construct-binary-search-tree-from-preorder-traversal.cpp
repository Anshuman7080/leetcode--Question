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
int find(vector<int>& nums,int start){
    for(int i=start+1;i<nums.size();i++){
        if(nums[i]>nums[start]){
            return i;
        }
    }
    return nums.size();
}
TreeNode* solve(vector<int>& nums,int start,int end){
    if(start>end){
        return NULL;
    }

TreeNode* root=new TreeNode(nums[start]);
int index=find(nums,start);

root->left=solve(nums,start+1,index-1);
root->right=solve(nums,index,end);

return root;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return solve(preorder,0,preorder.size()-1);
        
    }
};