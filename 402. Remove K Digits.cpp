class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<int>s ; 
        string ans = ""; 
        
        int n = num.size() ; 
        for(int i=0;i<n;i++){
            while(!s.empty() && s.back() > (num[i]-'0') && k>0){
                s.pop_back();
                k--;
            }
           if(!s.empty() && num[i]=='0')  s.push_back((num[i]-'0'));
          else if(num[i]!='0') s.push_back((num[i]-'0'));
        }
        while(!s.empty() && k--){
            s.pop_back();
        }
        for(auto it : s){
            ans+= ((char)(it+48)); 
        }
    return ans.size()==0?"0":ans;
    }
};
