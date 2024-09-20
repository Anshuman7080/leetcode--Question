class Solution {
    private:
    void solve(int n,int right ,int left,string& str,vector<string>&ans){
        
if(right+left==2*n){
    ans.push_back(str);
    return;
}

        if(left<n){
            str.push_back('(');
            solve(n,right,left+1,str,ans);
            str.pop_back();
        }

        if(right<left){
            str.push_back(')');
            solve(n,right+1,left,str,ans);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {

    vector<string>ans;
    string str;
    solve(n,0,0,str,ans);
        return ans;
    }
};