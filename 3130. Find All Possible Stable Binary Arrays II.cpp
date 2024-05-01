const int mod=1e9+7; 
int dp[1003][1003][2]; 
int prefix[1003][1003][2] ;

class Solution {
public:
    int prefix_sum(int zero,int one,int limit,int last_val){
        if(zero<0 || one<0) return 0;

        int&val = prefix[zero][one][last_val]; 
        if(val!=-1) return val; 
        int ans = 0 ; 
        ans = (ans+solve(zero,one,limit,last_val) + prefix_sum(zero-1,one,limit,last_val))%mod; 
        ans = (ans+ prefix_sum(zero,one-1,limit,last_val))%mod; 
        ans = (ans- prefix_sum(zero-1,one-1,limit,last_val))%mod; 

        return val = ans;
    }
    int solve(int zero,int one,int limit,int last_val){
        if(zero<0 || one<0) return 0;
        if(zero==0 && one==0){
            return 1;
        }
        int &val= dp[zero][one][last_val];
        if(val!=-1) return val;
        int ans=0; 
            if(last_val==0){
                //solve(zero-limit...zero-1,one,1) 
                ans=(prefix_sum(zero-1,one,limit,1)-prefix_sum(zero-limit-1,one,limit,1))%mod ; 
                ans=(ans-prefix_sum(zero-1,one-1,limit,1))%mod;
                ans=(ans+prefix_sum(zero-limit-1,one-1,limit,1))%mod;
            }
            else{
               //solve(zero,one-limit...one-1,1) 
                ans=(prefix_sum(zero,one-1,limit,0)-prefix_sum(zero,one-limit-1,limit,0))%mod ; 
                ans=(ans-prefix_sum(zero-1,one-1,limit,0))%mod;
                ans=(ans+prefix_sum(zero-1,one-limit-1,limit,0))%mod;
            }
    return val=ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));  
        memset(prefix,-1,sizeof(dp));
        int ans =  (solve(zero,one,limit,0) + solve(zero,one,limit,1))%mod;
        return (ans+mod)%mod;
    }
};
