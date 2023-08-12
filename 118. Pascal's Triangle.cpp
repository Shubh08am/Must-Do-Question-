class Solution {
public:
    //O(N) TO GENERATE ROW -> NOT O(N*ROW) -> OPTIMIZED THE CALCULATION
    vector<int>generateRow(int n){
        vector<int>ans;
        ans.push_back(1) ; 
        int num = 1;
        for(int i=1;i<n;i++){
            num=num*(n-i) ; 
            num/=i;
            ans.push_back(num);
        }
    return ans;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows); 
        for(int i=0;i<numRows;i++) ans[i] = generateRow(i+1);
        return ans;
    }
};
