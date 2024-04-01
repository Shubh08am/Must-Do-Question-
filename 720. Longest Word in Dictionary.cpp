class Node{
 public:
    Node*links[26] ; 
    bool flag=false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void putKey(Node*node,char ch){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool getEnd(){
        return flag;
    }
};
class Trie{
public:
    Node*root; 
    Trie(){
        root = new Node();
    }
    void insert(string & words){
        int n=words.size();
        Node*node=root;
        for(int i=0;i<n;i++){
            if(!node->containsKey(words[i])){
                node->putKey(new Node(),words[i]);
            }
            node=node->get(words[i]);
        }
    node->setEnd();
    }
    bool startsWith(string & words){
        int n=words.size();
        Node*node=root;
        for(int i=0;i<n;i++){
            if(!node->containsKey(words[i])){
                return false;
            }
            else {
                node=node->get(words[i]);
              //  if(words=="banana") cout << words[i] << " " << node->getEnd() << "\n";
                //as from b no words start return false 
                if(node->getEnd()==false) return false;
            }
        }
    return node->getEnd();
    }
};
class Solution {
public:
        
    string longestWord(vector<string>& words) {
        Trie t; 
        for(auto&w:words) t.insert(w);
        string ans="";
        for(auto&w:words){
            string p=w;
            if(t.startsWith(w)){
                int oldLen = w.size() , newLen = ans.size() ; 
                if(oldLen>newLen){
                    ans=w;
                }
                else if(oldLen==newLen && ans>w){
                    ans=w;
                }
            }
        }
     return ans;
    }
};
