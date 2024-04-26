class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size(),i=-1,j=0,ans=0,prev=0; 
        while(j<n){
            if(nums[j]>=left && nums[j] <= right){
                ans+=j-i;
                prev=j-i;
            }
            else if(nums[j]<left){
                ans+=prev;
            }
            else if(nums[j]>right){
                i=j;
                prev=0;
            }
        j++;
        }
    return ans;
    }
};


