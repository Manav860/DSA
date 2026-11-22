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
    ListNode* ConvertArrtoLL(vector<int> &v){
        if(v.size()==0){
            return NULL;
        }
        ListNode* head=new ListNode(v[0]);
        ListNode*temp=head;
        for(int i=1;i<v.size();i++){
            ListNode*temp2=new ListNode(v[i]);
            temp->next=temp2;
            temp=temp2;
        }
        return head;
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> v;
        ListNode*temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        while(true){
            unordered_map<int,int> mp;
            mp[0]=-1;
            int sum=0;
            bool changed =false;
            for(int i=0;i<v.size();i++){
                sum=sum+v[i];
                if(mp.find(sum)!=mp.end()){
                    int start=mp[sum]+1;
                    v.erase(v.begin()+start,v.begin()+i+1);
                    changed=true;
                    break;
                }
                mp[sum]=i;
            }
            if(changed==false){
                break;
            }
        }
        ListNode* newhead=ConvertArrtoLL(v);
        return newhead;
    }
};