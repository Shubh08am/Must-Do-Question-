const int mod = 1e9+7; 
class Solution {
public:
    unordered_map<int,unordered_map<int,unordered_map<int,unordered_map<int,int>>>>dp; 
    int solve(int ind,vector<int>&nums,int k,int prev,int ans){
        int n = nums.size(); 
        if(k==0) return ans; 
        if(ind==n || k<0)   return 0;
        
        if (dp[ind][k][prev].find(ans) != dp[ind][k][prev+1].end()) return dp[ind][k][prev][ans];
        
        //take not take 
       int new_ans = prev!=-1?abs(nums[ind] - nums[prev]):ans ;
       int take = solve(ind+1,nums,k-1,ind,min(ans,new_ans))%mod ; 
       int notTake = solve(ind+1,nums,k,prev,ans)%mod ; 
   
     return dp[ind][k][prev][ans] = (take+notTake)%mod;
    }
    int sumOfPowers(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return solve(0,nums, k,-1,1e9);
    }
};
