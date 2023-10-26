//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	   map<char,int>m; 
	   for(auto i : pat) m[i]++; 
	   int unique = m.size() , win = pat.size() , cnt=0;
	   int i=0,j=0,n=txt.size();
	   while(j<n){
	       if(!--m[txt[j]]) unique--;
	       if(j-i+1==win){
	           if(unique==0) cnt++;
	           if(++m[txt[i++]]==1) unique++;
	       }
	   j++;
	   }
	  return cnt;
	}
};
