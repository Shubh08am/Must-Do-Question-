class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int n = nums.size() ; 
       int ans = INT_MIN ;
        /* // O(N^3)
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum =0 ; 
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                ans=max(ans,sum);
            }
        }
    return ans;
    */

   /* // O(N^2)
        for(int i=0;i<n;i++){
            int sum =0 ; 
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ans=max(ans,sum);
            }
        }
    return ans;
    */

     // O(N) 
     int curr_sum =0 ; 
     //sequence 
     int ansStart = -1 , ansEnd = -1 , start=0; 
        for(int i=0;i<n;i++){
         //   if(curr_sum==0) start=i;
            curr_sum+=nums[i] ; 
            if(curr_sum>ans) {
                ans=curr_sum;
                ansStart=start;
                ansEnd=i;
            }
            if(curr_sum<0) {
                curr_sum = 0 ;
                start=i+1;
            }
        }
    cout<<ansStart<<" "<<ansEnd<<"\n"; // required longest continuous subarray
    return ans;
    }
};
