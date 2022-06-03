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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| head->next==NULL) return head;
        ListNode* t=head;
        int n=0;
        while(t!=NULL){
            n++;
            t=t->next;
        }
        if(k>=n) k=k%n;
        for(int i=1;i<=k;i++){
            ListNode* temp=head;
            while(temp->next->next!=NULL) temp=temp->next;
            ListNode* nextptr=temp->next;
            temp->next=NULL;
            nextptr->next=head;
            head=nextptr;
        }
        return head;
    }
};