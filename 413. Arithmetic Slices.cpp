class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        for(int i=0;i<n-2;i++){
            if(nums[i+1]-nums[i]==nums[i+2]-nums[i+1]) dp[i+2]=1+dp[i+1];
        }
    return accumulate(dp.begin(),dp.end(),0);
    }
};
