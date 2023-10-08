/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        Node * newhead = new Node(-1);
        Node * ans = newhead ;
        if(head->data>=data){
             newhead->next=new Node(data); 
             newhead=newhead->next;
             newhead->next=head;
             return ans->next;
        }
        else{
            Node * newhead = new Node(data);
            Node*ans=head;
            Node*prev=NULL;
            while(head){
                if(head->data>=data){
                prev->next=newhead;
                newhead->next=head;
                return ans;
                }
            prev=head;
            head=head->next;
            }
            if(prev->data<=data) prev->next=new Node(data) ;
            return ans;
         } 
    }
};
