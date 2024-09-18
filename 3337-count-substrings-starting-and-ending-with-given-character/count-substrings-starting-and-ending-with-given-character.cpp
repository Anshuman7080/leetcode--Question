class Solution {
public:
    long long countSubstrings(string s, char c) {
        
        stack<int>st;
        long long cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==c){
                st.push(c);
                cnt+=st.size();
            }
        }
        return cnt;
    }
};