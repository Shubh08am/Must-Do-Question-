class Solution {
public:
    bool solve(bool turn,int n,vector<vector<int>>&dp){
        if(n==0){
            //if alice turn she looses 
            //if bob turn he losses
            return turn?0:1;
        }
        if(n<0){
            return false;
        }
        int &val=dp[n][turn];
        if(val!=-1) return val;

        bool result=(turn?0:1);

        for(int x=1;x*x<=n;x++){
            if(turn)  result |= solve(0,n-x*x,dp);
            else if(!turn)  result &= solve(1,n-x*x,dp);
        }
    return val=result;
    }
    bool winnerSquareGame(int n) {
        //n-perfect square 
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(1,n,dp);
    }
};
