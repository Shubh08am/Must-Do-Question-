/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // 15 13 15 7 8 15 25 48 
        // 0   1  2 3 4  5  6 7
        int mini=0;
     
     for(int i=0;i<n-1;i++){
         A[i+1]+=A[i];
         }
         
            //handle 0 cases separately
        // -1 1 -1 0 
        //-1 0 -1 0 
        for(int i=n-1;i>=0;i--){
        if(A[i]==0) {
            mini=i+1;
            break;
        }
         }  
         
       map<int,pair<int,int>>mp;
       map<int,int>m;
       for(int i=0;i<n;i++){
           if(m[A[i]]==0){
               mp[A[i]]={A[i],i};
               m[A[i]]++;
           }
           else{
               mini=max(mini,i-mp[A[i]].second);
           }
       }
       return mini;
    }
};
