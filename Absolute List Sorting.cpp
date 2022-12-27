/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */

/*Your method shouldn't print anything
 it should transform the passed linked list */
class Solution{
    
public:
    Node* sortList(Node** head)
    {
        // Your Code Here
        vector<int>v;
        Node*temp=*head;
        Node*q=*head;
        
        while(temp!=NULL){
            v.push_back(temp->data);
            temp=temp->next;
        }
        sort(v.begin(),v.end());
        
         for(int i=0; i<v.size(); i++){
        q->data=v[i];
        q=q->next;
    }
    return *head;
    }
};
