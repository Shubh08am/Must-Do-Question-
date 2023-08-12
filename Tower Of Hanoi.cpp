class Solution{
    public:
    void solve(int n,int from,int to,int aux,long long&ans){
        if(n==0) return ;
        ans++;
        //move n-1 rod to helper rod and keep only 1 rod in from rod 
        solve(n-1,from,aux,to,ans); 
        cout<< "move disk " << n << " from rod "<< from <<" to rod " << to <<"\n";
        //move n-1 rod from aux rod to destination rod using from rod as helper rod 
        solve(n-1,aux,to,from,ans);
    }
    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        long long ans = 0 ; 
        solve(N,from,to,aux,ans);
        return ans;
    }

};
