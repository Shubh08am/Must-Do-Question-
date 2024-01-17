/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
    // Write your code here. 

    Node*zero=new Node(-1);
    Node*zeroH=zero;
 Node*one=new Node(-1);
    Node*oneH=one; 
    Node*two=new Node(-1);
    Node*twoH=two;


    Node*t=head;
    while(t){
        if(t->data==0){
            zero->next=t;
            zero=zero->next;
        }
        if(t->data==1){
            one->next=t;
            one=one->next;
        }
        if(t->data==2){
            two->next=t;
            two=two->next;
        }
        t=t->next;
    }
    zero->next = (oneH->next?oneH->next:twoH->next);
    one->next = twoH->next;
    two->next=NULL;
    return zeroH->next;
}
