class Solution {
public:
    int first(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1 ,pos=-1; 
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                pos=mid;
            }
            if(nums[mid]<target){
                low=mid+1;
            }
            if(nums[mid]>=target){
                high=mid-1;
            }
        }
    return pos;
    }
    int last(vector<int>& nums, int target) {
        int low = 0 , high = nums.size()-1 ,pos=-1; 
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                pos=mid;
            }
            if(nums[mid]<=target){
                low=mid+1;
            }
            if(nums[mid]>target){
                high=mid-1;
            }
        }
    return pos;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
      int f = first(nums,target) ; 
      int s = last(nums,target) ;
      return {f,s};
    }
};
