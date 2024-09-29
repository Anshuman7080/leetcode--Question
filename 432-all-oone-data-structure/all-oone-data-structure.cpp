class AllOne {
public:

set<pair<int,string>>st;
unordered_map<string,int>fre;
    AllOne() {
        
    }
    
    void inc(string key) {

    st.erase({fre[key],key});
    fre[key]++;
    st.insert({fre[key],key});
        
    }
    
    void dec(string key) {
 st.erase({fre[key],key});
    fre[key]--;
    if(fre[key]>0){
    st.insert({fre[key],key});
    }
        
    }
    
    string getMaxKey() {

 if(st.size()==0){
    return "";
 }  

 return prev(st.end())->second;     
 

    }
    
    string getMinKey() {
        if(st.size()==0){
            return "";
        }
        return st.begin()->second;
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