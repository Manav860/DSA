class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }

        while(head!=NULL && head->val==val){
            ListNode* delnode=head;
            head=head->next;
            delete delnode;
        }

        ListNode* temp=head;

        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==val){
                ListNode* delnode=temp->next;
                temp->next=temp->next->next;
                delete delnode;
            }
            else{
                temp=temp->next;
            }
        }

        return head;
    }
};