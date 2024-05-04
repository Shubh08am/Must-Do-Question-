class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans=0;
        int n = word.size(); 
        unordered_map<int,int>freq; 
        freq[0]=1; 
        int mask=0; 
        for(int i=0;i<n;i++){
            int bit=(word[i]-'a'); 
            mask = mask^(1<<bit) ; 
            ans+=freq[mask] ; 
            freq[mask]++; 
            for(char ch='a';ch<='j';ch++){
                int newbit=(ch-'a'); 
                int newmask = mask^(1<<newbit) ; 
                ans+=freq[newmask];
            }
        }
    return ans;
    }
};
