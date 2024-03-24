class Node{
public:
    Node*links[26]; 
    bool flag = false; 
    int index,len=INT_MAX; 

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node*get(char ch){
        return links[ch-'a'];
    }
    void put(Node*node,char ch){
        links[ch-'a']=node;
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
        root=new Node();
    } 
    void insert(string &word,int ind){
        int n=word.size(); 
        Node*node=root; 
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                node->put(new Node(),word[i]);
            } 
            node=node->get(word[i]);//move before bcs first we have root node than node of trie formed 
            
            //equal length case already handled as for that we are storing lesser index only 
            
            //AT EVERY NODE STORING INDEX OF LONGEST COMMON SUFFIX {ALTHOUGH HERE WE SEARCH FOR PREFIX}
            if(node->len > n){
                node->index=ind;
                node->len=n;
                //cout << word << " "<< node->index << " "<< ind <<"\n" ;
            }
        }
    node->setEnd();
    }
    int startsWith(string&word){
        Node*node=root; 
        int n=word.size(),ans=-1; 
        for(int i=0;i<n;i++){
            if(!node->containsKey(word[i])){
                return ans; //no common suffix {ALTHOUGH HERE WE SEARCH FOR PREFIX}
            }
            else{
                //cout << word << " "<< node->index << " "<< ans <<"\n" ;
                node=node->get(word[i]);
                ans=node->index;
            }
        }
    return ans; 
    }
};
class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Trie t; 
        int n = wordsContainer.size(),smallest,smallest_size=INT_MAX; 
        for(int i=0;i<n;i++){
            string s = wordsContainer[i]; 
            reverse(s.begin(),s.end());
            int curr_size = s.size();
            if(smallest_size > curr_size){
                smallest=i;
                smallest_size=curr_size;
            }
            t.insert(s,i);
        }
        vector<int>indices ; 
        for(auto&word:wordsQuery){
            reverse(word.begin(),word.end()); 
            int curr_index = t.startsWith(word);
            indices.push_back(curr_index==-1?smallest:curr_index);
        }
    return indices; 
    }
};
