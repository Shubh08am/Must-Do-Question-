class Solution {
public:
    int solve(int ind,vector<int>& jobDifficulty, int d,vector<vector<int>>&dp) {
        //at ith day --> all prev day work done 
        int n=jobDifficulty.size(); 
        if(ind==n){
            if(d==0) return 0;
            else return 1e8;
        }
        if(d<0) return 1e8;
        int &val = dp[ind][d];
        if(val!=-1) return val ;
        val=1e8;
        int md=0;
        for(int par=ind;par<n;par++){
            //maxDifficulty choosen 
            md=max(md,jobDifficulty[par]);
            val=min(val,md+solve(par+1,jobDifficulty,d-1,dp));
        }
    return val;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        //PARTITION DP 
        int n=jobDifficulty.size(); 
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1)) ; 
        int ans=solve(0,jobDifficulty,d,dp);
        return ans>=1e8?-1:ans;
    }
};
