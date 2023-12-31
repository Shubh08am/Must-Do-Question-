class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        //O(NlogN) 
        // 0 1 .......good_till_l [till here sorted] x y z good_till_r a b c ..... n-2 n-1 
        //Remove from good_till_l+1 to good_till_r and at last sorted part
        int n=nums.size(),good_till_l=0,good_till_r=n-1,i=0;
        while(good_till_l<n-1 && nums[good_till_l+1]>nums[good_till_l]) good_till_l++;
        while(good_till_r>0 && nums[good_till_r-1]<nums[good_till_r]) good_till_r--;
        long long res=good_till_l==n-1?0:n-good_till_r+1; 
        for(int i=0;i<=good_till_l;i++){
            int valid_start = upper_bound(nums.begin()+good_till_r,nums.end(),nums[i])-nums.begin(); 
            res+=n-valid_start+1;
        }
    return res;
    }
};
