class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here 
        vector<pair<int,int>>vp ;
        for(int i=0;i<n;i++){
            vp.push_back({end[i],start[i]});
        }
        sort(vp.begin(),vp.end()); 
        int st=vp[0].first ,cnt=0 ; 
        for(int i=1;i<n;i++){
            if(vp[i].second > st){
                cnt++;
                st = vp[i].first ;
            }
        }
    return cnt+1;
    }
};
