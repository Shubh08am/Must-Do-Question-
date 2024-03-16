class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n = nums.size(); 
       //find the largest sub-array with sum as 0 
        int i=0,j=0,len=0,sum=0; 
        unordered_map<int,int>prefix ; 
        while(j<n){
            sum+=(nums[j]==1?1:-1); 
            if(sum==0){
                len=max(len,j+1);
            }
            //Calculate the length and update maxLen:
            if (prefix.find(sum) != prefix.end()) {
                int currlen = j-prefix[sum];
                len = max(len, currlen);
            }
            if(prefix.find(sum)==prefix.end()){
                prefix[sum]=j;
            }
        j++;
        }
    return len;
    }
};
