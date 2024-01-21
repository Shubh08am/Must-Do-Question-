class Solution {
public:
    int solve(vector<int>&nums,int ind,vector<int>&dp){
        int n=nums.size();
        if(ind<0) return 0;
        if(ind==0) return nums[0];
        int &val=dp[ind];
        if(val!=-1) return val;
        return val=max(nums[ind]+solve(nums,ind-2,dp),solve(nums,ind-1,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        //return solve(nums,n-1,dp);
        /*dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i-1],nums[i]+(i>1?dp[i-2]:0));
        }
    return dp[n-1];
    */
    int prev2=0,prev=nums[0],curr=0;
    for(int i=1;i<n;i++){
        curr=max(prev,nums[i]+(i>1?prev2:0));
        prev2=prev;
        prev=curr;
    }
    return prev;
    }
};
