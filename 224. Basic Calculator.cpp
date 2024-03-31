class Solution {
public:
    bool isDigit(char ch){
        return ch>='0' && ch<='9';
    }
    int calculate(string s) {
        //stack 
        stack<int>st; 
        int result=0,n=s.size(),i=0,sign=1; 
        while(i<n){
          if(isDigit(s[i])){
              int currResult=0;
            while(isDigit(s[i])){
                currResult=currResult*10 + (s[i]-'0'); //for multiple digit like 11 , 12 
                i++;
            }
            currResult*=sign;
            result+=currResult;
            i--;//one position ahead if curr number is digit
          }
            if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(result); 
                st.push(sign) ; //indicates +ve sign by 1 
                result=0; //reset result and sign to 0 and 1 
                sign=1;
            }
            else if(s[i]==')'){
                result*=st.top(); //st.top() indicating the sign 
                st.pop(); 
                result+=st.top(); //this indicates the prev results 
                st.pop();
            }
            i++;
        }
    return result;
    }
};
