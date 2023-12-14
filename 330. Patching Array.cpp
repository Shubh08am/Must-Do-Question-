class Solution {
public:
    int minPatches(vector<int>& nums, int target) {
          //max 2 multiple 
        long long curr_sum=1,need=0,n=nums.size(),i=0;
        while(curr_sum<=target){
            if(i<n && curr_sum>=nums[i]){
                curr_sum+=nums[i];
                i++;
            }
            else{
                curr_sum<<=1;
                need++;
            }
        }
    return need;
    }
};
