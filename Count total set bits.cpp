//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here 
        int p = log2(n) ; 
        if(n==0) return 0; 
        return p*(1<<p)/2 + (n-(1<<p)+1) + countSetBits(n-(1<<p)) ; 
    }
};
