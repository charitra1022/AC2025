// Day 33
// Task 1: https://leetcode.com/problems/my-calendar-i/description/
// Date: 02-02-2023


// APPROACH 1: make a vector of start and end times in successful submissions, and iterate over all entries if anyone of them violates the booking time
// Time Complexity: O(N^2)
// Space Complexity: O(N)
// where N is the number of times the function is invoked

class MyCalendar {
public:
    // store successful booking timings
    vector<pair<int,int>> booking;

    MyCalendar() {}

    // check if given timing overlaps with incoming timings
    bool isPossible(pair<int,int>inter, int start, int end) {
        // if the incoming timing is outside of the given timing
        if(inter.first >= end || inter.second <= start)
            return true;
        // otherwise false
        return false;
    }
    
    bool book(int start, int end) {
        // first time is successful
        if(booking.size()==0){
            booking.emplace_back(make_pair(start,end));
            return true;
        }

        // iterate over all timings, if anyone violates, then false
        for(auto i: booking) {
            if(!isPossible(i, start, end))
                return false;
        }
        // all timings are good, so successful
        booking.emplace_back(make_pair(start,end));
        return true;
    }
};



// APPROACH 2: maitain a map of timings, and apply upper_bound
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// where N is the number of times the function is invoked

class MyCalendar {
public:
    // store booking timings
    map<int, int> bookings;

    MyCalendar() {}
    
    bool book(int start, int end) {
        // check if there exists an end that is just greater than incoming start
        auto it = bookings.upper_bound(start);

        // if doesnt exist, or if its start is greater equal to the incoming end
        // its start should be after our incoming end
        if(it==bookings.end() || it->second >= end) {
            bookings.insert({end, start});
            return true;
        } 
        // otherwise, overlaps
        return false;
    }
};
