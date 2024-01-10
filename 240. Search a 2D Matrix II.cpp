class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        /*
        int row=0,col=n-1;
        while(row<m && col>=0){
            if(matrix[row][col]==target){
                return true;
            }
            if(matrix[row][col]>target){
                col--;
            }
            else if(matrix[row][col]<target){
                row++;
            }
        }
        */
        int row=m-1,col=0;
        while(row>=0 && col<n){
            if(matrix[row][col]==target){
                return true;
            }
            if(matrix[row][col]>target){
                row--;
            }
            else if(matrix[row][col]<target){
                col++;
            }
        }
    return false;
    }
};
