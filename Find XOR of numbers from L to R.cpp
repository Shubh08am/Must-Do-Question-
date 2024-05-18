// User function Template for C++

class Solution {
  public:
    int solve(int x){
        if(x%4==0) return x; 
        if(x%4==1) return 1; 
        if(x%4==2) return x+1; 
        return 0;
    }
    int findXOR(int l, int r) {
                 /*
                 100
                 101 
                 001 
                 110 
                 111 
                 */
     return solve(l-1)^solve(r) ;
    }
};
