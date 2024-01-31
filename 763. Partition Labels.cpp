class Solution {
public:
    vector<int> partitionLabels(string s) {
      int n=s.size(),j=0;
      unordered_map<char,int>pos;
      vector<int>ans; 
      for(int i=0;i<n;i++){
          pos[s[i]]=i;
      }
      while(j<n){
          int farthest=j; 
          for(int i=j;i<=farthest;i++){
              farthest=max(farthest,pos[s[i]]);
          }
          //cout<<j<<" "<<farthest<<"\n";
          ans.push_back(farthest-j+1);
          j=farthest+1;
      }  
    return ans;
    }
};
