class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n=s.size(),i=0,j=n-1,step=0; 
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }
            else{
                //abb ->handle odd cases bring in middle position 
                int dummy_j=j;
                while(s[i]!=s[dummy_j]){
                    dummy_j--;
                }
                if(i==dummy_j){
                        swap(s[dummy_j],s[dummy_j+1]);
                        step++;
                }
                else{
                    while(dummy_j<j){
                        swap(s[dummy_j],s[dummy_j+1]);
                        step++;dummy_j++;
                    }
                    i++;j--;
                }
            }
        }
    return step;
    }
};
