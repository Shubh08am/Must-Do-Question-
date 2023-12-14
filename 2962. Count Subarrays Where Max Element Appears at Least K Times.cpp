class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long cnt=0,mx=*max_element(nums.begin(),nums.end()),n=nums.size(),i=0,j=0,occ=0; 
        while(j<n){
            occ+=mx==nums[j];
            if(occ>=k){
                while(occ>=k){
                    cnt+=n-j;
                    occ-=mx==nums[i++];
                }
            }
        j++;
        }
    return cnt;
    }
};
