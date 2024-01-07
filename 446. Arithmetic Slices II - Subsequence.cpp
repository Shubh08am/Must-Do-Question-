class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
    long n= nums.size(), las=0;
        map<pair<long,long>,long>dp;
        //at jth position with how much diff -> how many no of slices possible
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                long d=1ll*nums[i]-1ll*nums[j];
                dp[{i,d}]++;
                if(dp[{j,d}]>=1){ 
                        dp[{i,d}]+=dp[{j,d}];
                        las+=dp[{j,d}];
                }
            }
        }
        return las;
    }
};
