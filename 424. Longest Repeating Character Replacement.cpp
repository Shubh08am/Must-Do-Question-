class Solution {
public: 
// T.C -> O(26*n) --> 26 bcs we are finding most freq char again and again we can optimize it using a variable and maximizing it 
//Optimize one :- uses a variable instead of iterating in map for most freq char
    int mostFreqChar(unordered_map<char,int>&freq){
        int max_freq = 0 ; 
        for(auto it : freq) {
            max_freq = max(max_freq , it.second);
        }
        return max_freq;
    }
    int characterReplacement(string s, int k) {
        // window length - most freq char <= k --> valid and try to maximize it 
        unordered_map<char,int>freq;
        int i=0,j=0,max_freq=0,res=0;
        while(j<s.size()){
            freq[s[j]]++;
            //see for most freq character 
      //      max_freq = mostFreqChar(freq);  //T.C(O(26*N))
        max_freq = max(max_freq,freq[s[j]]);  //T.C(O(N))
            int windowLen = j-i+1; 

            //see for valid condition 
        if(windowLen - max_freq <=k ) {
         res=max(res,windowLen);
        }
        else if(windowLen - max_freq > k){
            //remove cal for i 
            freq[s[i]]--;
            i++;
        }
        j++;
        }
        return res;
    }
};
