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
    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr=slow->next;
        ListNode* prev=NULL;
        ListNode* nex;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            
            prev=curr;
            curr=nex;
        }
        fast=head;
        while(prev!=NULL){
            if(fast->val!=prev->val) return false;
            prev=prev->next;
            fast=fast->next;
        }
        return true;
    }
};