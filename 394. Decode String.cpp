class Solution {
public:
    string decodeString(string s) {
        string ans="";
        int n=s.size();
        stack<char>st; 
        for(int i=0;i<n;i++){
            if(s[i]==']'){
                string prev="";
                while(!st.empty()){
                    if(st.top()=='['){
                        st.pop();
                        string occ="";
                        while(!st.empty() && isdigit(st.top())){
                            occ=st.top()+occ;
                            st.pop();
                        }
                        int occ2=stoi(occ);
                        string curr=prev; 
                        while(occ2-->1) curr+=prev;
                        //cout<<curr<<"\n";
                        for(auto&ch:curr){
                            st.push(ch);
                        }
                        break;
                    }
                    else{
                        prev=st.top()+prev;
                        st.pop();
                    }
                }
            }
            else{
                cout<< s[i]<<" ";
                st.push(s[i]);
            }
        }
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
    }
};
