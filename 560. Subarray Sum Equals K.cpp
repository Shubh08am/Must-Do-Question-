class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //hashing no sliding windows as -ve elements are present 
        //prefix sum 
        /*
       [3 4 7 2 -3 1 4 2]
       prefix sum - 3 7 14 16 13 14 18 20 
       if in prefix sum any value == k take it 
       if in prefix sum (ith value of prefix sum - k ) present take it 
        */ 
        int cnt=0;
        unordered_map<int,int>freq;
        for(int i=1;i<nums.size();i++){
            nums[i]+=nums[i-1];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k) cnt++;
            //now see for nums[i]-k value 
            if(freq[nums[i]-k]>0) cnt+=freq[nums[i]-k];
            //insert in map 
            freq[nums[i]]++;
        }
        
        return cnt;
    }
};
