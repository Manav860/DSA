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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp=head;
        vector<int> v;
        while(temp!=NULL){
            if(temp->val<x){
                v.push_back(temp->val);
            }
            temp=temp->next;
        }
        ListNode* temp2=head;
        while(temp2!=NULL){
            if(temp2->val>=x){
                v.push_back(temp2->val);
            }
            temp2=temp2->next;
        }
        int i=0;
        ListNode* temp3=head;
        while(temp3 !=NULL){
            temp3->val=v[i];
            i++;
            temp3=temp3->next;
        }
        return head;
        
    }
};