class MyCalendar {
public:
    vector<pair<int, int>> books;
    
    MyCalendar() {
        
    }
    
//     bool book(int start, int end) {
//         for(int i=0;i<v.size();i++){
//             if(start>=v[i][0] && end<v[i][1]) return false;
            
//             if(start>=v[i][0] && start<v[i][1] && end>=v[i][1]) return false;
//         }
//         v.push_back({start,end});
//         sort(v.begin(),v.end());
//         return true;
//     }
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */