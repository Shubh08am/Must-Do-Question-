/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        Node* p = NULL , *c = head ; 
        while(c){
            c->prev = c->next; 
            c->next = p;
            p=c;
            c=c->prev;
        }
    return p;
    }
};
