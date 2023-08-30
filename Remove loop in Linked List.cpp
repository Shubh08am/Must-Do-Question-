/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list. 
    Node* FCD(Node*head){
          Node*slow = head , *fast = head ; 
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) return slow;
        }
    return NULL;
    }
    Node*startingNodeOfLoop(Node*head,Node*intersect){
          Node*nd = head ; 
        while(nd!=intersect){
            nd=nd->next;
            intersect=intersect->next;
        }
     return nd;
    }
    void removeLoop(Node* head)
    {
         if(!head || !head->next) return ; 
         
         Node*intersect = FCD(head) ; 
         //cout << intersect->data << "\n";
         if(!intersect) return;
         Node*start = startingNodeOfLoop(head,intersect) ; 
         
         //prevous node of start next pointed to null to remove loop 
         Node*prev = start ; 
         while(prev->next != start){
             prev=prev->next;
         }
         prev->next = NULL ; 
    }
};
