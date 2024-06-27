class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        //sweepline algorithm 
        vector<int>prefix(n+1,0) ; 
        //find no of passenger at each position 
        for(auto&b:bookings){
            int first=b[0],last=b[1],seats=b[2];
            prefix[first-1]+=seats;
            prefix[last]-=seats;
        }
        prefix.pop_back();
        for(int i=1;i<n;i++) prefix[i]+=prefix[i-1];
        return prefix;
    }
};
