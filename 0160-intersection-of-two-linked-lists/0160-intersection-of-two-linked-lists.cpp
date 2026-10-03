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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mpp;
        ListNode*temp=headA;
        while(temp!=NULL){
            mpp[temp]++;
            temp=temp->next;
        }
        ListNode*temp1=headB;
        while(temp1!=NULL){
            if(mpp.find(temp1)!=mpp.end()){
                return temp1;
            }
            temp1=temp1->next;
        }
        return NULL;
        
    }
};