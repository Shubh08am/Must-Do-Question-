class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // Prefix sum and remainder property 
        unordered_map<int,int>mp;
        mp[0]=1;
        int prefixSum = 0 , cnt =0 ;
        for(int i=0;i<nums.size();i++){
            //don't add all number -> Runtime can occur in this type of quest 
            //better to add remainder if -ve handle it by adding k 
            prefixSum = (prefixSum + (nums[i]%k) + k ) %k ;
            cnt+=mp[prefixSum];
            mp[prefixSum]++;
        }
    return cnt;
    }
};
