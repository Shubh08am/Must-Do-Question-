/*
What does it mean for Alice  to win? Alice  will win if score(Alice ) >= score(Bob ), but this also means score(Alice ) - score(Bob ) >= 0, so here you have a common parameter which is a score variable. The score parameter really means score = score(Alice ) - score(Bob ).

Now, if each player is suppoed to play optimally, how do you decide this with one variable?

Well since Alice  is playing optimally, he wants to maximize the score variable because remember, Alice  only wins if score = score(Alice ) - score(Bob ) >= 0 Alice  should add to the score because he wants to maximize it.
Since Bob  is also playing optimally, he wants to minimize the score variable, since if the score variable becomes negative, Bob  has more individual score than Alice . But since we have only one variable, Bob  should damage the score (or in other words, subtract from the score).
*/

class Solution {
public:
    int solve(int i,int j,bool turn,vector<int>& piles,vector<vector<int>>&dp) {
        if(i>j) return 0;
        int &val=dp[i][j];
        if(val!=-1) return val;
        int alice=0,bob=0;
        //Alice goes 
        if(turn){
           alice = max(piles[i]+solve(i+1,j,0,piles,dp) ,piles[j]+solve(i,j-1,0,piles,dp));
        }
        else{
            bob = min(-piles[i]+solve(i+1,j,1,piles,dp) ,-piles[j]+solve(i,j-1,1,piles,dp));
        }
    return val=max(alice,bob);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        cout << solve(0,n-1,1,piles,dp) ;
        return solve(0,n-1,1,piles,dp);
    }
};
