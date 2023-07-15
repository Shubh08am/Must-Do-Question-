class Solution {
public:
    bool canPlace(char ch,int i,int j,vector<vector<char>>& board){
        for(int k=0;k<9;k++){
            //col check
            if(board[k][j]==ch) return false;
            //row check
            if(board[i][k]==ch) return false;
            //3*3 check 
            int nr = 3*(i/3)+k/3;
            int nc = 3*(j/3)+k%3;
             if(board[nr][nc]==ch) return false;
        }
    return true;
    }
    bool solve(vector<vector<char>>& board) {
        int n = board.size() , m = board[0].size() ; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(canPlace(ch,i,j,board)){
                            board[i][j]=ch;
                            if(solve(board)) return true;
                            else board[i][j] ='.' ;
                        }
                    }
                return false; //can't place 1-9 on board[i][j] 
                }
            }
        }
    return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board) ; 
    }
};
