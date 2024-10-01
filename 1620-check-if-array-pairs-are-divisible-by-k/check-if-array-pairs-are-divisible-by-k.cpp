class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        unordered_map<int,int>mapi;

        for(int val:arr){
            int rem= ((val)%k+k)%k;
            mapi[rem]++;
        }

        if(mapi[0]%2!=0){
            return false;
        }

        for(int i=1;i<=k/2;i++){
            if(mapi[i]!=mapi[k-i]){
                return false;
            }
        }

        return true;
    }
};