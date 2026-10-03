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
        // BRUTE APPROACH

        // unordered_map<ListNode*,int> mpp;
        // ListNode*temp=headA;
        // while(temp!=NULL){
        //     mpp[temp]++;
        //     temp=temp->next;
        // }
        // ListNode*temp1=headB;
        // while(temp1!=NULL){
        //     if(mpp.find(temp1)!=mpp.end()){
        //         return temp1;
        //     }
        //     temp1=temp1->next;
        // }
        // return NULL;

        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int count=0;
        int count1=0;
        while(tempA!=NULL){
            count++;
            tempA=tempA->next;
        }
        while(tempB!=NULL){
            count1++;
            tempB=tempB->next;
        }
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int diff=abs(count-count1);
        for(int i=1;i<=diff;i++){
            if(count>count1){
                temp1=temp1->next;
            }
            else if (count<count1){
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL || temp2!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return NULL;
        
    }
};