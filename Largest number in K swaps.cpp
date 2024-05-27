class Solution
{
    public:
    //Function to find the largest number after k swaps. 
    string solve(int ind,string &str,int k){
        int n=str.size(); 
        if(ind>=n || k==0) return str ; 
        string nt = solve(ind+1,str,k) ; 
        string t ; 
        for(int j=ind+1;j<n;j++){
            if(k>0 && str[j]>str[ind]){
                swap(str[ind],str[j])  ; 
                t = max(t,solve(ind+1,str,k-1)) ; 
                swap(str[ind],str[j])  ; 
            }
        }
    return max(t,nt);
    }
    string findMaximumNum(string str, int k)
    {
        return solve(0,str,k);
    }
};
