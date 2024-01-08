/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    //1-> copy node
    void insertCopyInBetween(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            Node*copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    }
    //2-> create random pointer
    void connectRandomPointers(Node*head){
        Node*temp=head;
        while(temp!=NULL){
            Node*copyNode=temp->next;
            if(temp->random) copyNode->random=temp->random->next;
            else copyNode->random=NULL;
            temp=temp->next->next;
        }
    }
    //3-> create next pointer and separate original and copy list
    Node*getDeepCopyList(Node*head){
        Node*temp=head;
        Node*dummyNode=new Node(-1);
        Node*res=dummyNode;

        while(temp!=NULL){
            //create new ll
            res->next=temp->next;
            res=res->next;

            //disconnect and go back to new ll 
            temp->next=temp->next->next;
            temp=temp->next;
        }
    return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
