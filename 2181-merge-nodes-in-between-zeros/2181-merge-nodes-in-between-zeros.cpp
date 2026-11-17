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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*dummyNode=new ListNode(-1);
        ListNode*temp1=dummyNode;
        ListNode*temp=head->next;
        int sum=0;
        while(temp!=NULL){
            if(temp->val!=0){
                sum=sum+temp->val;
            }
            else{
                ListNode*temp2=new ListNode(sum);
                temp1->next=temp2;
                temp1=temp1->next;
                sum=0;
            }
            temp=temp->next;
        }
        return dummyNode->next;
    }
};