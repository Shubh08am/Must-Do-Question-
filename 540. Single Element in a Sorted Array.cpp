class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size() ; 
     
    if(n==1) return nums[0] ; 
    if(nums[0]!=nums[1]) return nums[0] ; 
    if(nums[n-1]!=nums[n-2]) return nums[n-1] ; 

    int low = 1 , high = n-2 ; 

    //EO EO EO E OE OE OE 
    // BEFORE E -> EO PAIRS 
    // AFTER E -> OE PAIRS 

    while(low<=high){

        int mid = (low+high)/2; 

        if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid] ; 

        // ODD EVEN POSITION LOGIC 
        if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            //ELEMENT IN RIGHT HALF 
            low=mid+1;
        }

        else high=mid-1;//ELEMENT IN LEFT HALF 
    } 
    return -1;
    }
};
