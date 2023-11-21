const int N = 1e5+1;
class Solution {
public:
    int dp[N][2];
    int solve(int ind,bool canSwap,vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        if(ind==0) return 0;
        int &ans = dp[ind][canSwap] ; 
        if(ans!=-1) return ans;
        ans=1e9;
        int val1 = nums1[ind-1];
        int val2 = nums2[ind-1];
        if(canSwap){
            swap(val1,val2);
        }
        //No swap
        if(val1<nums1[ind] && val2<nums2[ind]){
            ans=min(ans,solve(ind-1,0,nums1,nums2));
        }
        //Swap
        if(val1<nums2[ind] && val2<nums1[ind]){
            ans=min(ans,1+solve(ind-1,1,nums1,nums2));
        }
    return ans ;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        int n=nums1.size();
        return min(solve(n-1,0,nums1,nums2),1+solve(n-1,1,nums1,nums2));
    }
};
