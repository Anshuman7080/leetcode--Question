class Solution {
    private:
    void solve(vector<int>& nums,vector<vector<int>>& ans,int index,vector<int>&temp){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        vector<bool>used(21,0);

for(int i=index;i<nums.size();i++){
  
  if(used[nums[i]+10]==0){
    swap(nums[i],nums[index]);
    solve(nums,ans,index+1,temp);
    swap(nums[i],nums[index]);
    used[nums[i]+10]=1;
  }
    
}



    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        vector<vector<int>> ans;
      vector<int>temp;
        int index=0;
        solve(nums,ans,index,temp);
        return ans;
    }
};