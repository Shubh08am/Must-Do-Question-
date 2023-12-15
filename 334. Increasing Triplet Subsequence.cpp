class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //longest increasing subsequence 
        vector<int>lis;
        int n=nums.size();
        lis.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(lis.back()<nums[i]) lis.push_back(nums[i]); 
            else{
                int pos = lower_bound(lis.begin(),lis.end(),nums[i])-lis.begin(); 
                lis[pos]=nums[i];
            }
        }
    return lis.size()>=3;
    }
};
