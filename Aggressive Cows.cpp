class Solution {
public:
    bool isPossible(int mid,int n,int k,vector<int> &stalls) {
      int last = stalls[0] , r=1 ; 
      
      for(int i=1;i<n;i++){
          if(stalls[i]-last >= mid){
              r++;
              last=stalls[i];
          }
          if(r>=k) return 1;
      }
     return 0;
    }
    int solve(int n, int k, vector<int> &stalls) {
    sort(stalls.begin(),stalls.end()) ; 
    int low = 1, high=stalls[n-1]-stalls[0] ,ans=0; 
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(isPossible(mid,n,k,stalls)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return ans;
    }
};
