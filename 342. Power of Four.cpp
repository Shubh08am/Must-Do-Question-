class Solution {
public:
    bool isPowerOfFour(int n) {
        // return n<=0?0:(n&(n-1))==0 && n%3==1; 
       // return n<=0?0:(n&~(n-1))==n && n%3==1;
       // return n<=0?0:(n&(-n))==n && n%3==1;
        return n<=0?0:(ceil((log10(n))/(log10(4))) == floor((log10(n))/(log10(4))))  ;
    }
};
