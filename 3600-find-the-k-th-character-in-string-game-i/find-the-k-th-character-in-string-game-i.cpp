class Solution {
public:
    char kthCharacter(int k) {

        string ans="a";
        while(ans.length()<k){
                string str="";
            for(int i=0;i<ans.length();i++){
              str+=ans[i]+1;
            }
            ans+=str;
        }

        return ans[k-1];
        
    }
};