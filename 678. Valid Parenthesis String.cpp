class Solution {
public:
    bool checkValidString(string s) {
        //see one sol is dp one thats easy 
        //try greedy 
        int maxDiff=0,minDiff=0; 
        for(auto&ch:s){
            if(ch=='('){
                maxDiff++;minDiff++;
            }
            if(ch==')'){
                maxDiff--;minDiff--;
            }
            if(ch=='*'){
                maxDiff++;minDiff--;
            }
            if(maxDiff<0) return 0;
            minDiff=max(0,minDiff); 
        }
    return minDiff==0;
    }
};
