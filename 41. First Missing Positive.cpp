class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //cyclic sort 
        int n=nums.size(),i=0;
        while(i<n){
            long correctPosition=1ll*nums[i]-1;
            if(nums[i]>0 && nums[i]<=n && nums[i]!=nums[correctPosition]){
                swap(nums[i],nums[correctPosition]);
            }
            else{
                i++;
            }
        }
        for(auto i : nums) cout << i <<" ";
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
