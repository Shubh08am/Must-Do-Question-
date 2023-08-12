class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //O(N)
        vector<int>row; 
        row.push_back(1) ;
        rowIndex++; 
        long num = 1 ; 
        for(int i=1;i<rowIndex;i++){
            num=num*(rowIndex-i) ; 
            num/=i;
            row.push_back(num) ;     
        }
    return row;
    }
};
