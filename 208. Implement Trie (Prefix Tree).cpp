class Node{
public:
    Node* links[26];
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
class Trie {
public:
    Node*root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node*node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->putKey(new Node(),word[i]);
            }
            node=node->get(word[i]);
        }
    node->setEnd();     
    }
    
    bool search(string word) {
        Node*node=root;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
    return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node*node=root;
        int n=prefix.size();
        for(int i=0;i<n;i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
