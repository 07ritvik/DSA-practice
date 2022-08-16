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
    ListNode* merge(ListNode* h1,ListNode* h2){
        if(h2==NULL) return h1;
        if(h1==NULL) return h2;
        
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(h1!=NULL && h2!=NULL){
            if(h1->val<=h2->val){
                temp->next=h1;
                temp=h1;
                h1=h1->next;
            }
            else{
                temp->next=h2;
                temp=h2;
                h2=h2->next;
            }
        }
        while(h1!=NULL){
                temp->next=h1;
                temp=h1;
                h1=h1->next;            
        }
        while(h2!=NULL){
                temp->next=h2;
                temp=h2;
                h2=h2->next;            
        }
        ans=ans->next;
        return ans;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1) return lists[0];
        ListNode* ans=merge(lists[0],lists[1]);
        for(int i=2;i<lists.size();i++){
            ans=merge(ans,lists[i]);
        }
        return ans;

    }
};