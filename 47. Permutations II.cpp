class Solution {
public:
void solve(vector<vector<int>>&ans,vector<bool>&freq,vector<int>&ds,vector<int>&arr,int n){
       if(ds.size()==n){
           ans.push_back(ds);
           return;
        }
       for(int j=0;j<n;j++){
            if(j>0 && arr[j]==arr[j-1] && freq[j-1]==1) continue;
            if(!freq[j]){
                ds.push_back(arr[j]);
                freq[j]=1;
                solve(ans,freq,ds,arr,n);
                ds.pop_back();
                freq[j]=0;
            }
       }
   }
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>ans;
        vector<bool>freq(n,0);
        vector<int>ds;
        sort(arr.begin(),arr.end());
        solve(ans,freq,ds,arr,n);
        return ans;
    }
};
