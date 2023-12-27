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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*dummy=new ListNode(0) ; 
        dummy->next=head;
        ListNode*curr=dummy,*prev=dummy,*nex=dummy;
        int length=0;
        while(curr->next){
            curr=curr->next;
            length++;
        }
        while(length>=k){
            //Every k size group first node is curr and 2nd node is nex 
            curr=prev->next;
            nex=curr->next;
            //k-1 links changed
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex; 
                nex=curr->next;
            }
        prev=curr;
        length-=k;
        }
    return dummy->next;
    }
};
