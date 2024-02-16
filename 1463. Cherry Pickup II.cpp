class Solution {
public:
    int solve2(int i,int j1,int j2,vector<vector<int>>& grid ,vector<vector<vector<int>>>&dp){
         int n=grid.size() , m=grid[0].size() , maxi=-1e9;
         //base case:- (1)Boundary Check 
         if(j1<0 || j1>=m || j2<0 || j2>=m) return 0;

         //(2) destination reach i.e last row 
         if(i==n-1){
             if(j1==j2) return grid[n-1][j1];  //both robots at same cell :- Count once only 
             else return grid[n-1][j1]+grid[n-1][j2]; //both robots at different cell :- Count for both differently 
         }
        
        if(dp[i][j1][j2] !=-1) return dp[i][j1][j2] ;
         //Explore All paths i.e 9 paths 
         for(int dj1=-1;dj1<=+1;dj1++){
             for(int dj2=-1;dj2<=+1;dj2++){
                if(j1==j2) maxi = max(maxi,grid[i][j1] + solve2(i+1,j1+dj1,j2+dj2,grid,dp));   
             else maxi = max(maxi,grid[i][j1]+grid[i][j2]+solve2(i+1,j1+dj1,j2+dj2,grid,dp)); 
           }
        }
    return dp[i][j1][j2] = maxi;
    } 
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size() , m=grid[0].size() ;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1))) ;
        return solve2(0,0,m-1,grid,dp);
    }
};
