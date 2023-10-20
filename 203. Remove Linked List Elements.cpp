/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        //leading node removed
        while(head && head->val==val){
            ListNode*currNode=head;
            head=head->next;
            delete(currNode);
        }
        //2 pointer logic
        ListNode*prev=head,*curr=head;
        while(curr){
            if(curr->val==val){
                ListNode*currNode=curr;
                prev->next=curr->next;
                curr=curr->next;
                delete(currNode);
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
    return head;
    }
};
