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
    // BRUTE FORCE
    // ListNode* ConvertArr(vector<int> &v){
    //     if(v.size()==0){
    //         return NULL;
    //     }
    //     ListNode* head=new ListNode(v[0]);
    //     ListNode*mover=head;
        
    //     for(int i=1;i<v.size();i++){
    //         ListNode*temp=new ListNode(v[i]);
    //         mover->next=temp;
    //         mover=temp;
    //     }
    //     return head;

    // }  
    // ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    //     vector<int> v;
    //     ListNode*temp1=list1;
    //     ListNode*temp2=list2;
    //     while(temp1!=NULL){
    //         v.push_back(temp1->val);
    //         temp1=temp1->next;
    //     }
    //     while(temp2!=NULL){
    //         v.push_back(temp2->val);
    //         temp2=temp2->next;
    //     }
    //     sort(v.begin(),v.end());
    //     ListNode* head=ConvertArr(v);
    //     return head;
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        ListNode*dummyNode=new ListNode(-1);
        ListNode*temp=dummyNode;
        ListNode* t1=list1;
        ListNode* t2=list2;
        while(t1!=NULL && t2!=NULL){
            if(t1->val<t2->val){
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1){
            temp->next=t1;
        }
        else{
            temp->next=t2;
        }
        return dummyNode->next;

        
    }
};