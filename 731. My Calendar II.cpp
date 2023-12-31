class MyCalendarTwo {
public:
    //Difference Array Technique 
    map<int,int>DiffArr;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        DiffArr[start]++;
        DiffArr[end]--; 
        int booking=0;
        for(auto&val:DiffArr){
            booking+=val.second; 
            if(booking>=3) {
                //remove this event added 
                DiffArr[start]--;
                DiffArr[end]++; 
                return false; 
            }
        }
    return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
