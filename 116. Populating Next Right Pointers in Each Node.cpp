/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root ; 
        Node*curr = root; 
        while(curr->left){
            Node*temp=curr; 
            //SUB-TREE -> AT A LEVEL CHECK 
            while(curr){
                curr->left->next=curr->right; 
                if(curr->next) curr->right->next = curr->next->left; 
                else curr->right->next = NULL;
                curr=curr->next;
            }
        //MAIN-TREE EACH LEVEL CHECK 
        curr=temp->left;
        }
    return root;
    }
};
