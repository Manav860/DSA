class Solution {
public:

    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newhead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode*getKthNode(ListNode*head,int k){
        ListNode*temp=head;
        for(int i=1;i<k;i++){
            if(temp==NULL){
                return NULL;
            }
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*prev=NULL;
        while(temp!=NULL){
            ListNode*kthNode=getKthNode(temp,k);
            if(kthNode==NULL){
                if(prev){
                    prev->next=temp;
                    break;
                }
            }
            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;
            reverse(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prev->next=kthNode;
            }
            prev=temp;
            temp=nextNode;
        }
        return head;

    }
};