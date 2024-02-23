#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //max meeting room -> lowest room number 
        //sort on the basis of start time in this type of questions 
        //and keep track of free room and busy room using 2 data structure separately 

        map<int,int>rooms;
        priority_queue<ll,vector<ll>,greater<ll>>freeRoom; //roomNo
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>busyRoom; //{when_this_room_becomes_free,roomNo}
        sort(meetings.begin(),meetings.end());

        //Initially all rooms are free 
        for(int roomNo=0;roomNo<n;roomNo++) freeRoom.push(roomNo); 

        //Now,traverse the meeting and start allocating meetings
        //CASE-1 -> we have freeRooms left with us 
        //CASE-2 -> no freeRooms available than assign the meeting after we have completed one meeting 

        for(auto&curr_meet:meetings){
            int start_time = curr_meet[0],end_time=curr_meet[1]; 
            //CASE-2 :- take the busyRoom with least end_time and try to make it free 
            //possible only when start_time>busyRoom end_time 
            while(!busyRoom.empty() && busyRoom.top().first<=start_time){
                int roomNo=busyRoom.top().second;
                freeRoom.push(roomNo);
                busyRoom.pop();
            }
            //CASE-1 
            if(!freeRoom.empty()){
                int meetingRoom=freeRoom.top();
                freeRoom.pop();
                //now,this room has became busy see when it will become free 
                busyRoom.push({end_time,meetingRoom});
                rooms[meetingRoom]++;
                continue;
            }
            //CASE 2:- Waiting for the busyRoom least end_time to get free 
            //and we will make that room busy again 
            ll least_end_time=busyRoom.top().first ; 
            int meetingRoom = busyRoom.top().second ;
            busyRoom.pop();
            rooms[meetingRoom]++;
            busyRoom.push({least_end_time+end_time-start_time,meetingRoom});

        }
        int roomNo=0,maxMeeting=0; 
        for(auto&r:rooms){
            if(r.second>maxMeeting){
                maxMeeting=r.second; 
                roomNo=r.first;
            }
        }
    return roomNo;
    }
};
