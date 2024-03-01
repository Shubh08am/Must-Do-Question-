class Solution {
public:
    const int P=31;
    const int MOD=1e9+7;
    long long RABIN_KNAP(string&s,unordered_map<int,int>&freq){
        int n=s.size();
        long long ans=0,Prefix_Hash=0,Suffix_Hash=0; 
        
        vector<long long> p_pow(n+1); 
        p_pow[0] = 1; 
        for (int i = 1; i < p_pow.size(); i++) p_pow[i] = (p_pow[i-1] * P) % MOD;
        
         for(int i=0;i<n;i++){
            Prefix_Hash=(Prefix_Hash*P+(s[i]-'a'+1))%MOD;
            Suffix_Hash=(Suffix_Hash+(s[n-i-1]-'a'+1)*p_pow[i])%MOD;
            //cout << Prefix_Hash << " "<< Suffix_Hash <<" "<< p_pow[i]<<"\n";
            ans+=Prefix_Hash==Suffix_Hash?freq[Suffix_Hash]:0;
        }
        freq[Prefix_Hash]++;
        //cout<<"\n";
    return ans;
    }
    long long countPrefixSuffixPairs(vector<string>& words) {
        //RABIN KNAP -> ROLLING HASHING 
        long long ans=0; 
        unordered_map<int,int>freq; 
        for(auto&w:words){
            ans+=RABIN_KNAP(w,freq);
        }
    return ans;
    }
};
