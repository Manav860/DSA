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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode*temp=NULL;
        ListNode*left1=head;
        for(int i=1;i<left;i++){
            temp=left1;
            left1=left1->next;
        }
        ListNode*right1=left1;
        for(int i=left;i<right;i++){
            right1=right1->next;
        }
        ListNode*temp3=right1->next;
        right1->next=NULL;
        ListNode*newhead=reverse(left1);
        if(temp !=NULL){
            temp->next=newhead;
        }
        else{
            head=newhead;
        }
        left1->next=temp3;
        return head;



        
    }
};