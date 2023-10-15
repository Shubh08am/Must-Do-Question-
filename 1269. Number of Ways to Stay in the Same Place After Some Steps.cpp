class Solution {
public:
    const int mod = 1e9+7; 
    int solve(int ind,int steps,int arrLen,vector<vector<int>>&dp){
        if(ind>=arrLen || ind<0){
            return 0;
        }
        if(steps==0){
            return ind==0;
        }
        if(dp[ind][steps]!=-1) {
            return dp[ind][steps];
        }
        long R = solve(ind+1,steps-1,arrLen,dp)%mod ; 
        long L = solve(ind-1,steps-1,arrLen,dp)%mod ; 
        long S = solve(ind,steps-1,arrLen,dp)%mod ; 
    return dp[ind][steps] = (R+L+S)%mod ;
    }
    int tab(int steps,int arrLen){
        int move = min(steps/2+1,arrLen);
        vector<vector<int>>dp(move+1,vector<int>(steps+1,0)) ;
        dp[0][0]=1; 
            for(int step=1;step<=steps;step++){
                for(int ind=move-1;ind>=0;ind--){
                long R=0,L=0,S=0;
                S = dp[ind][step-1] ; 
                if(ind>0) L = dp[ind-1][step-1] ; 
                if(ind<move) R= dp[ind+1][step-1] ;

            dp[ind][step]=(L+R+S)%mod; 
            }
        }
    return dp[0][steps];
    }
        int tabS(int steps,int arrLen){
        int move = min(steps/2+1,arrLen);
        vector<int>prev(move+1,0),curr(move+1,0);
        prev[0]=1; 
            for(int step=1;step<=steps;step++){
                for(int ind=move-1;ind>=0;ind--){
                long R=0,L=0,S=0;
                S = prev[ind] ; 
                if(ind>0) L = prev[ind-1] ; 
                if(ind<move-1) R= prev[ind+1] ;

            curr[ind]=(L+R+S)%mod; 
            }
            prev=curr;
        }
    return prev[0];
    }
    int numWays(int steps, int arrLen) {
       // WHY THOSE WHO CAN'T  REMEMBER THE PAST ARE CONDEMNED TO REMEMBER IT :) 
        int move = min(steps/2+1,arrLen);
        //OBSERVATION :- WE CAN MOVE STEPS/2+1 TIMES MAX RIGHT OR LEFT 
        // JUST IGNORING ARRLEN FACT 
        vector<vector<int>>dp(move,vector<int>(steps+1,-1));
      //  return solve(0,steps,move,dp);
     // return tab(steps,arrLen);
     return tabS(steps,arrLen);
    }
};
