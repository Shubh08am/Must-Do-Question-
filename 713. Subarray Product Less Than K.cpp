class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) { 
    if(k<=1) return 0;
      int i=0,j=0,product=1,cnt=0,n=nums.size();
      while(j<n) {
            product*=nums[j];
          //remove cal for i 
         while(product>=k){
                    product/=nums[i];
                    i++;
          } 
        cnt+=j-i+1;
        j++;
        }
        return cnt;  
    }
};
