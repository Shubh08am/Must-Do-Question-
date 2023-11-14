class Solution {
public:
    int dp[31][31];
    int solve(int i,int j,vector<int>& stones,vector<int>& prefix, int k) {
        if(i>=j) return 0;
        int maxSum=1e9;
        int &res=dp[i][j];
        if(res!=-1) return res;
        for(int l=i;l<j;l+=k-1){
            int curr = solve(i,l,stones,prefix,k) + solve(l+1,j,stones,prefix,k) ;
            maxSum=min(maxSum,curr);
        }
        if((j-i)%(k-1)==0)maxSum+=prefix[j+1]-prefix[i]; 
        return res=maxSum;
    }
    int mergeStones(vector<int>& stones, int k) {
        int n=stones.size();
        int m=n;
        while(m%k==0) m/=k;
        while(m>1) m-=k-1;
        if(m!=1) return -1;
        // partition dp 
        memset(dp,-1,sizeof(dp));
        vector<int>prefix(n+1,0);
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+stones[i-1];
        }
       // for(auto it : prefix) cout<<it<<" ";
        return solve(0,n-1,stones,prefix,k);
    }
};
