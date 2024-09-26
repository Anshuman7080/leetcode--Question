class MyCalendar {
public:
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        for (const auto& interval : ans) {
            if (max(interval.first, start) < min(interval.second, end)) {
                return false; 
            }
        }
        ans.push_back({start, end});
        return true;
    }

private:
    vector<pair<int, int>> ans;
};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */