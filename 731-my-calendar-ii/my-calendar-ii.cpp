class MyCalendarTwo {
public:
    vector<pair<int, int>> ans;
    vector<pair<int, int>> overlap_book;

    MyCalendarTwo() {
        
    }

    bool book(int start, int end) {
        for (auto &overlap : overlap_book) {
            if (max(start, overlap.first) < min(end, overlap.second)) {
                return false;
            }
        }

        for (auto &val : ans) {
            if (max(start, val.first) < min(end, val.second)) {
                overlap_book.push_back({max(start, val.first), min(end, val.second)});
            }
        }
        ans.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */