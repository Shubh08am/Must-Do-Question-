class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size(); 
        vector<vector<int>>robots(n); 
        for(int i=0;i<n;i++){
            robots[i]={positions[i],healths[i],i,directions[i]=='L'?-1:1};
        }
        sort(robots.begin(),robots.end()); 
        vector<vector<int>>currRobot; 
        for(int i=0;i<n;i++){
            vector<int>curr=robots[i]; 
            while(!currRobot.empty() && currRobot.back()[3]==1 && curr[3]==-1){
                //3 cases :- case 1 equal 
                if(currRobot.back()[1]==curr[1]){
                    currRobot.pop_back(); 
                    curr[1]=0;
                    break;
                }
                //case 2 :- left > right 
                else if(currRobot.back()[1] < curr[1]){
                    currRobot.pop_back(); 
                    curr[1]--;
                }
                //case 3 :- left < right 
                else if(currRobot.back()[1] > curr[1]){
                    vector<int>new_curr=currRobot.back(); 
                    currRobot.pop_back(); 
                    new_curr[1]--;
                    curr[1]=0;
                    currRobot.push_back(new_curr);
                    break;
                }
            }
            //if health still left of curr than take that health 
            if(curr[1]>0) currRobot.push_back(curr);
        }
        //we want result on the basis of index 
        sort(currRobot.begin(),currRobot.end(),[&](auto&a,auto&b){return a[2]<b[2] ;});
        vector<int>robotLeft; 
        for(auto&r:currRobot) robotLeft.push_back(r[1]); 
        return robotLeft;
    }
};
