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
    ListNode*ConvertArr(vector<int> &v){
        if(v.size()==0){
            return 0;
        }
        ListNode*head=new ListNode(v[0]);
        ListNode*temp1=head;
        
        for(int i=1;i<v.size();i++){
            ListNode*temp=new ListNode(v[i]);
            temp1->next=temp;
            temp1=temp;
        }
        return head;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*temp=head;
        map<int,int> mp;
        while(temp!=NULL){
            mp[temp->val]++;
            temp=temp->next;
        }
        vector<int> v;
        for(auto x:mp){
            if(x.second==1){
                v.push_back(x.first);
            }
        }
        ListNode*newhead=ConvertArr(v);
        return newhead;


    }
};