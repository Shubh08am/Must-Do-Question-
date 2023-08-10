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
    ListNode*reverse(ListNode*head){
        ListNode*prev = NULL , *curr = head ; 
        while(curr){
            ListNode*forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
    return prev;
    }
    int getDecimalValue(ListNode* head) {
        ListNode*head2=reverse(head);
        int number = 0 ;  
        int exponent = 0 ; 
        while(head2){
            number+=(1<<exponent)*head2->val;
            exponent++;
            head2=head2->next;
        }
    return number;
    }
};
