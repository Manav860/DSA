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
    ListNode* reverseLinkedList(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newhead=reverseLinkedList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;
    }
    bool isPalindrome(ListNode* head) {

        // BRTUE FORCE

        // ListNode*temp1=head;
        // vector<int> v;
        // while(temp1!=NULL){
        //     v.push_back(temp1->val);
        //     temp1=temp1->next;
        // }
        // reverse(v.begin(),v.end());
        // ListNode* temp=head;
        // int i=0;
        // while(temp!=NULL){
        //     if(temp->val!=v[i]){
        //         return false;
        //     }
        //     i++;
        //     temp=temp->next;
        // }
        // return true;
        ListNode*slow=head;
        ListNode*fast=head;
        if(head==NULL || head->next==NULL){
            return true;
        }
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newhead=reverseLinkedList(slow->next);
        ListNode*first=head;
        ListNode*second=newhead;
        while(second!=NULL){
            if(first->val!=second->val){
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLinkedList(newhead);
        return true;
        
    }
};