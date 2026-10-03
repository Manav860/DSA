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
    bool isPalindrome(ListNode* head) {
        ListNode*temp1=head;
        vector<int> v;
        while(temp1!=NULL){
            v.push_back(temp1->val);
            temp1=temp1->next;
        }
        reverse(v.begin(),v.end());
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL){
            if(temp->val!=v[i]){
                return false;
            }
            i++;
            temp=temp->next;
        }
        return true;
        
    }
};