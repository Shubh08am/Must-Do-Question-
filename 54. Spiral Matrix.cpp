class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>spiral ; 
        int m = matrix.size() , n = matrix[0].size() ; 
        int total = 0; 
        int startingRow = 0 , startingCol = 0 ; 
        int endingRow = m-1 , endingCol = n-1 ; 
        while(total<n*m){
            //first row 
            int i=startingCol;
            while(i<=endingCol && total<n*m){
                spiral.push_back(matrix[startingRow][i++]) ; 
                total++;
            }
            startingRow++; 
 
            //lastCol 
            i=startingRow;
            while(i<=endingRow && total<n*m){
                spiral.push_back(matrix[i++][endingCol]) ; 
                total++;
            }
            endingCol--; 
 
            //lastRow 
            i=endingCol;
            while(i>=startingCol && total<n*m){
                spiral.push_back(matrix[endingRow][i--]) ; 
                total++;
            }
            endingRow--;
 
            //firstCol 
            i=endingRow;
            while(i>=startingRow && total<n*m){
                spiral.push_back(matrix[i--][startingCol]) ; 
                total++;
            }
            startingCol++;
         }
    return spiral;
    }
};
