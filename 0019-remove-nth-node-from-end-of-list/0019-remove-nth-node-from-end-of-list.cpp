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
        // brute force approach

        // ListNode*temp1=head; 
        // int count=0;
        // while(temp1!=NULL){
        //     count++;
        //     temp1=temp1->next;
        // }
        // int element=count-n;
        // if(element==0){
        //     head=head->next;
        //     delete temp1;
        //     return head;
        // }
        // ListNode* temp=head;
        // for(int i=1;i<element;i++){
        //     temp=temp->next;
        // }
        // ListNode* toDelete=temp->next;
        // temp->next=temp->next->next;
        // delete toDelete;
        // return head;

        // optimal approach using slow and fast pointers

        ListNode* slow=head;
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* delNode=slow->next;
        slow->next=slow->next->next;
        delete delNode;
        return head;
    }
};