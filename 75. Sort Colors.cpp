class Solution {
public:
    void sortColors(vector<int>& nums) {
        //  THREE POINTERS
        // 0 TO LOW-1 -> 0 
        // LOW TO MID-1 -> 1 
        //MID TO HIGH -> RANDOM UNSORTED 
        // HIGH+1 TO N-1 -> 2 

        //T.C -> O(N) -> IN EVERY STEP 1 ELEMENT IN SORTED CORRECT PLACE
        int low = 0 , mid = 0 , high = nums.size()-1 ;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]) ; 
                low++;mid++;
            }    
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[high]); 
                high--;
            }
        }
    }
};
