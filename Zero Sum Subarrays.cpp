//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
       long long ans=0;
       map<long long int,long long  int>mp;

       for(int i=0;i<n-1;i++) {
           arr[i+1]+=arr[i];
       }

        for(int i=0;i<n;i++) {
        if(arr[i]==0) ans++;
          mp[arr[i]]++;
       }
       //6 5 2 6 4 6 10 16 4 -3 
      // 0 1 2 3 4 5 6   7 8  9 
      /*
      1-> 0th index se 3rd  as vha tak ka sum is 6 and 0th ka bhi 6 i.e total added = 0
      2-> 0th index se 5th  as vha tak ka sum is 6 and 0th ka bhi 6 i.e total added = 0
      3-> 3rd index se 5th  as vha tak ka sum is 6 and 3rd ka bhi 6 i.e total added = 0
      4-> 4th index se 8th  as vha tak ka sum is 4 and 4th ka bhi 4 i.e total added = 0
      */
        for(auto it : mp) {
             ans+=(it.second * (it.second-1) )/2;
        }
        return ans;
    }
};
