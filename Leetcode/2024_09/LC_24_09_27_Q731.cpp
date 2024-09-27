// Link - https://leetcode.com/problems/my-calendar-ii/?envType=daily-question&envId=2024-09-27
// My Calendar II


class MyCalendarTwo {
public:
    map<int, int> events;
    
    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        events[start]++;
        events[end]--;
        int activeBookings = 0;
        
        for (auto &event : events) {
            activeBookings += event.second;

            if (activeBookings >= 3) {
                events[start]--;
                events[end]++;
                if (events[start] == 0) {events.erase(start);}
                if (events[end] == 0) {events.erase(end);}
                return false;
            }

            if(event.first > end) break;
        }
        return true;
    }
};


// class MyCalendarTwo {
// public:
//     MyCalendarTwo() {
        
//     }
//     vector<pair<pair<int, int>, int>> arr;
//     bool book(int start, int end) {
//         int count = 1;
//         for (auto it : arr) {
//             int r_start = it.first.first;
//             int r_end = it.first.second;
//             if (start < r_end && end > r_start) {
//                 count = it.second + 1;                                    
//                 if (count > 2) return false;
//             }
//                 cout << count << endl;
//         }
//         arr.push_back({{start, end}, count});
//         return true;
//     }
// };

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */