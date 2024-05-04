class Solution {
public:
    long long appealSum(string s) {
        //sum of all unique character of each substrings 
        long long prev=0; 
        int n=s.size(); 
        vector<int>pos(26,-1),count(n,0);
        for(int i=0;i<n;i++){
            int ch = s[i]-'a'; 
            long long val = (1ll*(i+1)*(i+2))/2 ; 
            if(pos[ch]==-1){
                count[i]=val-prev;
                pos[ch]=i;
            }
            else{
                count[i]=val-prev-pos[ch]-1; 
                prev+=pos[ch]+1; 
                pos[ch]=i;
            }
        }
        long long total=0; 
        for(int i=0;i<n;i++) {
            total+=count[i];
        }
        return total;
    }
};
