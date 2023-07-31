class Solution {
public:
    int findMin(vector<int>& nums) {
        // POINT OF ROTATION IS ANSWER 
        int n = nums.size() ; 
        int low=0,high=n-1, mini = INT_MAX;

        while(low<=high){
            int mid = low+(high-low)/2;

            //optimization -> search space sorted 
            if(nums[low]<=nums[high]){
                 mini=min(mini,nums[low]) ;
                 break;
            }
            //left half sorted
            if(nums[low]<=nums[mid]){
                //low is minimum 
                mini=min(mini,nums[low]) ; 
                low=mid+1;
            }
            //right half sorted
            else if(nums[mid]<=nums[high]){
                mini=min(mini,nums[mid]) ; 
                high=mid-1;
            }
        }
    return mini;
    }
};
