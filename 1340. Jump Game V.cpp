class Solution {
public:
    int solve(int ind,int n,vector<int>&arr,int d,vector<int>&dp){
        if(dp[ind]!=-1) return dp[ind];
        int left=0,right=0;

        //from ind-1 try left till possible 
        for(int i=ind-1;i>=max(ind-d,0);i--){
            if(arr[ind]>arr[i]){
                left=max(left,solve(i,n,arr,d,dp));
            }
            else break;
        }

        //from ind try right till possible 
        for(int i=ind+1;i<=min(ind+d,n-1);i++){
            if(arr[ind]>arr[i]){
                right=max(right,solve(i,n,arr,d,dp));
            }
            else break;
        }

    return dp[ind] = 1+max(left,right);
    }
    int maxJumps(vector<int>& arr, int d) {
        //go to every point and try both ways right and left upto d distance with given condition 
        int n=arr.size();
        // dp[i] is max jumps you can do starting from index i
        vector<int>dp(n,-1);
        int maxJump=0;
        for(int i=0;i<n;i++){
            maxJump=max(maxJump,solve(i,n,arr,d,dp));
        }
    return maxJump;
    }
};
