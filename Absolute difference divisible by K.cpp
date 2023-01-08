class Solution {
  public:
    long long countPairs(int n, int arr[], int k) {
        // code here
        long ans=0;
        
        unordered_map<int,int>mp;
        
          for(int i=0; i<n;i++){
              mp[arr[i]%k]++;
        }
        
        //7 need 3 and 11 need 7 & 3 
        //3-> 3 
        //1 2 3 4 
        // 1->2 and 0->2 
        for(int i=0;i<k;i++){
                 //7%4=3 take it 
                // 3%2=1 take it and 4%2=0 take it's freq
                long curr =mp[i];
                ans+=((curr*(curr-1))/2);
        }
        return ans;
    }
};
