class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //same logic of anagram 
        //i.e see for anagram of s1 in s2

         int i=0,j=0,n=s2.size() , windowSize = s1.size();
 unordered_map<int,int>freq;
for(auto it : s1) freq[it]++;
int uniqueElement = freq.size() ;

while(j<n){
       //decrease the freq of char of s if present in p 
         if(freq.find(s2[j])!=freq.end()) {
             freq[s2[j]]--;
            //when 0 remove it 
            if(freq[s2[j]]==0) {
                uniqueElement--;//that char is removed completely
            }
         }
      if(j-i+1 == windowSize){
        //restore every char freq 
        //restore ith char frequency
         if(uniqueElement==0) 
             //take in answer
             return true;
            if(freq.find(s2[i])!=freq.end()){ freq[s2[i]]++;
            //not always therefore in loop
            if(freq[s2[i]] == 1) uniqueElement++;//that char is back
            }
         i++;
    }
    j++;
}
 return 0;
    }
};
