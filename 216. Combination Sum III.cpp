class Solution {
public:
    void solve(int ind,int n,int k,vector<int>&ds,vector<vector<int>>&ans){
        if(k==0){
            if(n==0) ans.push_back(ds);
            return;
        }
        if(k<0 || n<0) return;
        for(int i=ind;i<=9;i++){
            ds.push_back(i);
            solve(i+1,n-i,k-1,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1,n,k,ds,ans);
        return ans;
    }
};
