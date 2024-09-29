class AllOne {
public:
unordered_map<string,int>fre;
    AllOne() {
        
    }
    
    void inc(string key) {
        
        fre[key]++;
    }
    
    void dec(string key) {
        
        fre[key]--;

    }
    
    string getMaxKey() {

      int mx=0;
      string ans="";
      for(auto& st:fre){
        if(st.second>mx){
            mx=st.second;
            ans=st.first;
        }
      }
      return ans;

    }
    
    string getMinKey() {
        int min=INT_MAX;
        string ans="";
        for(auto& st:fre){
            if(st.second<min && st.second!=0){
                  min=st.second;
                  ans=st.first;
            }           
        }
 return ans;

    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */