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
        ListNode* t=head;
        for(int i=0;i<k;i++){
            if(t==NULL) return head;
            t=t->next;
        }
        ListNode* currptr=head;
        ListNode* prevptr=NULL;
        ListNode* nextptr;
        int cnt=0;
        int n;
       
        while(currptr!=NULL&&cnt<k){
            nextptr=currptr->next;
            currptr->next=prevptr;
            prevptr=currptr;
            currptr=nextptr;
            cnt++;
        }
        if(currptr!=NULL){
            head->next=reverseKGroup(currptr,k);
        }
        return prevptr;
        // if(head==NULL || head->next==NULL) return head;
        // int length =0;
        // ListNode* temp=head;
        // while(temp!=NULL){
        //     length++;
        //     temp=temp->next;
        // }
        // ListNode* dummy=new ListNode(0);
        // dummy->next=head;
        // ListNode* pre=dummy;
        // ListNode* cur;
        // ListNode* nex;
        // while(length>=k){
        //     cur=pre->next;
        //     nex=cur->next;
        //     for(int i=1;i<k;i++){    // k-1 links change krni padegi
        //         cur->next=nex->next;
        //         nex->next=pre->next;
        //         pre->next=nex;
        //         nex=cur->next;
        //     }
        //     pre=cur;
        //     length-=k;
        // }
        // return dummy->next;
    }
};