/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Using HASHING
        // unordered_map<ListNode*,int> mp;
        // ListNode*temp=head;
        // while(temp!=NULL){
        //     if(mp.find(temp)!=mp.end()){
        //         return temp;
        //     }
        //     mp[temp]++;
        //     temp=temp->next;
            
        // }
        // return NULL;

        // USING SLOW AND FAST POINTER(TORTOISE AND HARE ALGORITHM)
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                break;
            }
        }
        if(fast == NULL || fast->next == NULL){
            return NULL;
        }
        ListNode*slow1=head;
        while(slow1!=fast){
            slow1=slow1->next;
            fast=fast->next;
        }
        return slow1;
    }
};