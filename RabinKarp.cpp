//3008. Find Beautiful Indices in the Given Array II
#define ll long long
class Solution {
public:
    const int MOD = 1e9+9;
    const int P = 31;

    // Pattern = 's', Text = 't'
    vector<int> RabinKarp(const string& s, const string& t) {
        int S = s.size(), T = t.size();

        vector<ll> p_pow(max(S, T)); 
        p_pow[0] = 1; 
        for (int i = 1; i < p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1] * P) % MOD;

        vector<ll> h(T + 1, 0); 
        for (int i = 0; i < T; i++)
            h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % MOD; 

        ll h_s = 0; 
        for (int i = 0; i < S; i++) 
            h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % MOD; 

        vector<int> occurrences;
        for (int i = 0; i + S - 1 < T; i++) {
            ll cur_h = (h[i+S] + MOD - h[i]) % MOD;
            if (cur_h == h_s * p_pow[i] % MOD)
                occurrences.push_back(i);
        }
        return occurrences;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>result;
        int n=s.size(),len1=a.size(),len2=b.size();
        vector<int> a_indices = RabinKarp (a, s);
        vector<int> b_indices = RabinKarp (b, s);
        unordered_set<int>used;
        for(int i=0;i<a_indices.size();i++){
            //check between a_indices[i]-k to a_indices[i]+k -> b_indices[i] present 
            int value1 = a_indices[i]-k ; 
            int value2 = a_indices[i]+k ; 
            auto it1 = lower_bound(b_indices.begin(),b_indices.end(),value1) ; 
            auto it2 = lower_bound(b_indices.begin(),b_indices.end(),value2) ; 
            if(it1 == b_indices.end()) continue; 
            else if(abs((*it1)-a_indices[i])<=k) {
              if(!used.count(a_indices[i]))  result.push_back(a_indices[i]);
                used.insert(a_indices[i]);
            }
            if(it2 == b_indices.end()) continue; 
            else if(abs((*it2)-a_indices[i])<=k) {
              if(!used.count(a_indices[i]))  result.push_back(a_indices[i]);
                used.insert(a_indices[i]);
            }
        }
    return result;
    }
};
