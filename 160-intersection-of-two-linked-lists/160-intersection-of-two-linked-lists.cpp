/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // while(headB!=NULL){
        //     ListNode* temp=headA;
        //     while(temp!=NULL){
        //         if(temp==headB){
        //             return temp;
        //         }
        //         temp=temp->next;
        //     }
        //     headB=headB->next;
        // }
        ListNode* temp=headA;
        int l1=0,l2=0;
        while(temp!=NULL){
            l1++;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            l2++;
            temp=temp->next;
        }
        int diff=l2-l1;
        if(diff<0){
            while(diff++!=0) headA=headA->next;
            
        }
        else while(diff--!=0) headB=headB->next;
        
        while(headA!=NULL && headB!=NULL){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
};