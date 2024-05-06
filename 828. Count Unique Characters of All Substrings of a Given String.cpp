class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.size(); 
        vector<int>L(n,0),R(n,0); 
        vector<int>LastL(26,-1),LastR(26,n); 
        
        //see for every ith index -> left contribution in the answer and right contribution
        
        for(int i=0;i<n;i++){
            L[i]=i-LastL[s[i]-'A'];
            LastL[s[i]-'A']=i; 
        }
        
        for(int i=n-1;i>=0;i--){
            R[i]=LastR[s[i]-'A']-i;
            LastR[s[i]-'A']=i; 
        }
        
        int unique=0; 
        for(int i=0;i<n;i++){
            unique+= L[i]*R[i];
        }
    return unique; 
    }
};
