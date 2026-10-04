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
        ListNode*tail=head;
        int count=1;
        if(head==NULL || head->next==NULL){
            return head;
        }
        while(tail->next!=NULL){
            count++;
            tail=tail->next;
        }
        int rotation =k%count;
        if(rotation==0){
            return head;
        }
        ListNode*temp=head;
        for(int i=1;i<count-rotation;i++){
            temp=temp->next;
        }
        tail->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
        
        
    }
};