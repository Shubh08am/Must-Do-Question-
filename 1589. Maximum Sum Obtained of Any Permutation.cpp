class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        //SWEEP LINE || DIFFERENCE ARRAY TECHNOQUES
        //0 1 2 3 4 5 
        //freq[requests[i][0]]++ , freq[requests[i][1]+1]--; 
        //after that freq[i]+=freq[i-1];
        
        //0 0 0 0 0 0
        //1 0 0 -1 0 0 
        //1 1 0 -1 -1 0 
        //1 2 -1 -1 -1 0 
        //1 3 2 1 0 0 
        
        //now assign higher value according to higher frequency appearance 
        int n=nums.size(),m=requests.size(),total=0;
        const int mod=1e9+7;
        vector<int>freq(n,0);
        for(int i=0;i<m;i++){
            freq[requests[i][0]]++ ;
            if(requests[i][1]<n-1)  freq[requests[i][1]+1]--; 
        }
        for(int i=1;i<n;i++){
            freq[i]+=freq[i-1];
        }
        sort(freq.rbegin(),freq.rend()); 
        sort(nums.rbegin(),nums.rend()); 
        int j=0;
        for(int i=0;i<n;i++){
            if(freq[i]>0){
                total=(total+1ll*freq[i]*nums[j])%mod;
                j++;
            }
        }
        return total;
    }
};
