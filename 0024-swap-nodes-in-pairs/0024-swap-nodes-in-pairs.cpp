class Solution {
public:
    ListNode*reverse(ListNode*head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*newhead=reverse(head->next);
        ListNode*front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode*temp=head;
        ListNode*prev=NULL;
        ListNode*newhead=NULL;
        while(temp!=NULL && temp->next!=NULL){
            ListNode*nextpart=temp->next->next;
            temp->next->next=NULL;
            ListNode*curr=reverse(temp);
            if(newhead==NULL){
                newhead=curr;
            }
            else{
                prev->next=curr;
            }
            prev=temp;
            temp=nextpart;

        }
        if(temp!=NULL){
            prev->next=temp;
        }
        return newhead;
    }
};