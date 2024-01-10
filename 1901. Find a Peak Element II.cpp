class Solution {
public:
    int findMaxValueIndex(vector<vector<int>>& mat,int m,int n,int col) {
        int maxValue=-1,index=-1;
        for(int i=0;i<m;i++){
            if(mat[i][col]>maxValue){
                maxValue=mat[i][col];
                index=i;
            }
        }
    return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        //O(n*logm)
        int m=mat.size(),n=mat[0].size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=findMaxValueIndex(mat,m,n,mid);
            int val=mat[row][mid];
            int left = (mid-1>=0?mat[row][mid-1]:-1);
            int right = (mid+1<n?mat[row][mid+1]:-1);
            if(val>left && val>right) return {row,mid};
            else if(left>val) high=mid-1;
            else if(val<right) low=mid+1;
        }
    return {-1,-1};
    }
};
