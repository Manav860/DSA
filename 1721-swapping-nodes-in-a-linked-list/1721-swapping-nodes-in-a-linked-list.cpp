class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL) {
            return head;
        }
        ListNode* slow1 = head;
        ListNode* fast1 = head;
        for(int i = 1; i < k; i++) {
            fast1 = fast1->next;
        }
        ListNode* slow2 = fast1;
        while(fast1->next != NULL) {
            slow1 = slow1->next;
            fast1 = fast1->next;
        }
        int data1 = slow2->val;
        int data2 = slow1->val;

        slow2->val = data2;
        slow1->val = data1;

        return head;
    }
};