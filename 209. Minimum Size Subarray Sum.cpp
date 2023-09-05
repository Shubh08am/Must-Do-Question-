class Solution {
public:
    bool isPossible(int mid,int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size(),sum=0,currSum=0;
        while(j<n){
            sum+=nums[j];
            if(j-i+1 == mid){
                currSum = max(currSum,sum);
                sum-=nums[i++];
            }
        j++;
        }
    return currSum >= target ;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        // sliding window -> optimal 
        // doing binary search follow up -> O(nlogn)
        int n=nums.size(),low=1,high=n,ans=0;
        while(low<=high){
            int mid = low + (high-low)/2; 
            if(isPossible(mid,target,nums)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
    return ans;
    }
};
