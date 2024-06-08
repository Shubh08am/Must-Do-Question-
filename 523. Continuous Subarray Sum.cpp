class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //think remainder on curr sum -> if >=2 sub-array found -> true
        // [23,2,4,6,7] , k=6 -> [5,2,5,5,0] 
        // [3,2,2] , k=3 -> [0,2,2] -> fasle
        //[23,2,4,6,6] , k=7 -> [2,4,1,0,6]
        unordered_map<int,int>freq; 
        freq[0]=-1; // [2,1] , k=3 -> [2,0] -> 0 means multiple of k i.e index of 0 = 1 - freq[0] = 2 -> true
        int n=nums.size(),prefixSum=0;
        for(int i=0;i<n;i++){
            prefixSum=(prefixSum+nums[i])%k;
            if(freq.find(prefixSum)!=freq.end()){
                if(i-freq[prefixSum]>=2) return true;
            }
            else freq[prefixSum]=i;
        }
    return false;
    }
};
