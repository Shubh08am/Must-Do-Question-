#define ll long long
const int mod = 1e9+7;
const int N = 1e5+1;
class Solution {
public:
   // unordered_map<ll,unordered_map<ll,unordered_map<ll,unordered_map<ll,ll>>>>dp;
    int dp[N][2][3][2];
    ll solve(int ind,int n,int l,int e,int t){
        if(ind>=n) return (l==0 && e==0 && t==0) ;
        if(dp[ind][l][e][t]!=-1) return  dp[ind][l][e][t];
        ll ans=0;
        for(char ch='a';ch<='z';ch++){
            if(ch=='l' && l==1){
                ans = (ans+solve(ind+1,n,0,e,t))%mod;
            }
            else if(ch=='e' && e==1){
                ans = (ans+solve(ind+1,n,l,2,t))%mod;
            }
            else if(ch=='e' && e==2){
                ans = (ans+solve(ind+1,n,l,0,t))%mod;
            }
            else if(ch=='t' && t==1){
                ans = (ans+solve(ind+1,n,l,e,0))%mod;
            }
            else{
                ans = (ans+solve(ind+1,n,l,e,t))%mod;
            }
        }
    return dp[ind][l][e][t]=ans;
    }
    int stringCount(int n) {
        //4d dp 
        memset(dp,-1,sizeof(dp));
        return solve(0,n,1,1,1);
    }
};
