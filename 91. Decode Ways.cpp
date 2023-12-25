class Solution {
public:
    int solve(int ind,string&s,unordered_map<string,char>&valToChar,vector<int>&dp){
        int n=s.size();
        if(ind==n) return 1;
        int &val = dp[ind] ; 
        if(val!=-1) return val;
        val=0;
        string curr="";
        for(int par=ind;par<n;par++){
            curr+=s[par];
            if(valToChar.count(curr)){
                val+=solve(par+1,s,valToChar,dp);
            }
        }
        return val;
    }
    int numDecodings(string s) {
        unordered_map<string,char>valToChar;
        for(char ch='a';ch<='z';ch++){
            valToChar[to_string((ch-'a')+1)]=ch;
        }
        int n=s.size();
       // vector<int>dp(n,-1);
       // return solve(0,s,valToChar,dp);
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int ind=n-1;ind>=0;ind--){
            string curr="";
            for(int par=ind;par<n;par++){
                curr+=s[par];
                if(valToChar.count(curr)) dp[ind]+=dp[par+1];
            }
        }
    return dp[0];
    }
};
