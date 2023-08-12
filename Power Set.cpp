class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		   vector<string>ans; 
		   int n = s.size() ; 
		   int mask = (1<<n) ; 
		   
		   for(int i=1;i<mask;i++){
		       string se ; 
		       for(int j=0;j<n;j++){
		           //if(i&((1<<j))) se+=s[j] ;
		           if((i>>j)&1) se+=s[j] ;
		       }
		       ans.push_back(se);
		   }
		   sort(ans.begin(),ans.end()) ;
		  return ans;
		}
};
