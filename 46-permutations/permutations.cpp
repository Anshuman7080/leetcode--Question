class Solution {

    private:
    void solve(vector<int>&nums,vector<int>&temp, vector<bool>& visited,vector<vector<int>>&ans){
if(temp.size()==visited.size()){
    ans.push_back(temp);
    return;
}

        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                visited[i]=1;
                temp.push_back(nums[i]);
                solve(nums,temp,visited,ans);
                  visited[i]=0;
                temp.pop_back();
              
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
vector<vector<int>>ans;
vector<bool>visited(nums.size(),0);
vector<int>temp;
solve(nums,temp,visited,ans);
return ans;

        
    }
};














// class Solution {
// private:
// void solve(vector<int> nums,vector<vector<int>>& ans,int index){
//     if(index>=nums.size()){
//         ans.push_back(nums);
//         return ;
//     }

// for(int i=index;i<nums.size();i++){
//     swap(nums[index],nums[i]);
//     solve(nums,ans,index+1);
//     swap(nums[index],nums[i]);
// }


// }


// public:
//     vector<vector<int>> permute(vector<int>& nums) {

// vector<vector<int>>ans;
// int index=0;
// solve(nums,ans,index);
// return ans;


        
//     }
// };