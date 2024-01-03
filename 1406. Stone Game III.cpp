class Solution {
public:
    int solve(int i,bool turn,vector<int>& stoneValue,vector<vector<int>>&dp){
        int n=stoneValue.size();
        if(i>=n) return 0;
        int &val=dp[i][turn];
        if(val!=-1) return val;
        
        //if turn=1 Alice goes and maximize the result therefore take result as INT_MIN 
        //if turn=0 Bob goes and minimize the result therefore take result as INT_MAX
        int result=(turn?INT_MIN:INT_MAX),score=0;

        //We can take 1 to min(3,n-i) stones 
        
        for(int x=1;x<=min(n-i,3);x++){
            score+=stoneValue[i+x-1];
            //Alice goes -> Next time than bob goes(turn 0)-> update i to i+x as we took x stones 
            if(turn){
                result=max(result,score+solve(i+x,0,stoneValue,dp));
            }
            //Bob goes -> Next time than Alice goes(turn 1)-> update i to i+x as we took x stones 
            else{
                result=min(result,solve(i+x,1,stoneValue,dp));
            }
        }
    return val=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        //Same as Stone Game II
        int n=stoneValue.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int total=accumulate(stoneValue.begin(),stoneValue.end(),0);
        int alice=solve(0,1,stoneValue,dp),bob=total-alice;
        return bob<alice?"Alice":(bob>alice?"Bob":"Tie");
    }
};
