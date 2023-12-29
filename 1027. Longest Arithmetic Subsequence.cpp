class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n= nums.size(), las=1;
        vector<vector<int>>dp(n+1, vector<int>(1001, 1));
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                int d=nums[i]-nums[j];
                dp[i][d+500]= max(dp[i][d+500],1+dp[j][d+500]);
                las= max(las,dp[i][d+500]);
            }
        }
        return las;
    }
};
