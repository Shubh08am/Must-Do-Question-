class Solution {
public:
    const int mod=1e9+7; 
    int dp[201][201][2];
    int solve(int zero,int one,int limit,int last_val){
        if(zero<0 || one<0) return 0;
        if(zero==0 && one==0){
            return 1;
        }
        int &val= dp[zero][one][last_val];
        if(val!=-1) return val;
        int ans=0; 
        //try putting last_val k times than other val and see the ways
        for(int k=1;k<=limit;k++){
            if(last_val==0){
                ans+=solve(zero-k,one,limit,1); //after 0 place 1 
                ans%=mod;
            }
            else{
                ans+=solve(zero,one-k,limit,0); 
                ans%=mod;
            }
        }
    return val=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        return (solve(zero,one,limit,0) + solve(zero,one,limit,1))%mod;
    }
};
