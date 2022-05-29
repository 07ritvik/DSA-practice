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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=1;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        temp=head;
        n=cnt-n;
        cnt=1;
        if(n==1)return head->next;
        ListNode* prev=NULL;
        while(temp!=NULL){
            if(cnt==n){
                ListNode* todelete=temp;
                prev->next=temp->next;
                
                temp=temp->next;
                delete(todelete);
                break;   
            }
            cnt++;
            prev=temp;
            temp=temp->next;
        }
        return head;
        
    }
};