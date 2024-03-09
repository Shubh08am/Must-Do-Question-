class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<int>>AnagramPos; 
        for(int i=0;i<strs.size();i++){
            string curr = strs[i] ; 
            sort(curr.begin(),curr.end()) ; 
            AnagramPos[curr].push_back(i) ;
        }
        vector<vector<string>>ans(AnagramPos.size()); 
        int i=0; 
        for(auto&it : AnagramPos){
            for(auto& x : it.second) ans[i].push_back(strs[x]) ; 
            i++;
        }
    return ans;
    }
};
