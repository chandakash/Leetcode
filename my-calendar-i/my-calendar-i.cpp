class MyCalendar {
public:
    set<pair<int,int>> s;
    bool book(int start, int end) {
        // check if current time interval can be inserted or not
        auto itr = s.lower_bound({start,end});
        if(itr!=s.end() and end>itr->first)
            return false;
        if(itr!=s.begin() and (--itr)->second>start)
            return false;
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */