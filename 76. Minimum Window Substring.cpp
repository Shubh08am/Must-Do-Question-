class Solution {
public:
    string minWindow(string s, string t) {
        //sliding window of variable size 
        string ans="";
        unordered_map<int,int>freq;
        int i=0,j=0,n=s.size(),m=t.size();
        int start_index=0 , end_index = 1e5 ; 

        for(auto it : t) freq[it]++;
        int uniqueElement = freq.size() ; 

        while(j<n){
             freq[s[j]]--;
             //if 0 decrease unique element 
             if(freq[s[j]]==0) {
                 uniqueElement--;
             }
             
            //if uniqueElement becomes 0 than its possible that the window is possible answer 
            //but look for more minimum possible 
            if(uniqueElement==0){
            while(uniqueElement==0){
                //see the start_index and end_index of sub-string 
                //update if current sub-string  size is larger 
                int curr_substring_size = j-i+1 ;
                if(curr_substring_size < end_index){ 
                start_index = i ; 
                end_index = curr_substring_size ; 
                }

                //remove calulation for i 
                freq[s[i]]++;
                if(freq[s[i]] > 0) uniqueElement++;

                i++;
            }
            }
          j++;
        }
        //if no sub-string found 
        if(end_index == 1e5) {
            ans= "";
        }
        else{
           ans = s.substr(start_index,end_index);
        }
        return ans;
    }
};
