class Solution {
public:
    vector<int>z_function(string &s){
        int n=s.size(),l=0,r=0;
        vector<int>z(n,0);
        for(int i=1;i<n;i++){
            if(i<=r){
                z[i]=min(r-i+1,z[i-l]);
            }
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }
            if(z[i]+i-1>r){
                l=i;
                r=z[i]+i-1;
            }
        }
    return z;
    }
    int minimumTimeToInitialState(string word, int k) {
        //learn from code n code -> string algorithm 
        int n=word.size(),cnt=0; 
        vector<int>z=z_function(word); 
      // for(auto&it:z) cout<<it<<" ";
        for(int i=k;i<n;i+=k){
            cnt++;
            if(z[i]==n-i) return cnt;
        }
        return cnt+1; //rebuild whole string
    }
};
