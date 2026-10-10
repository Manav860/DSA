
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newhead1 = reverse(l1);
        ListNode* newhead2 = reverse(l2);
        ListNode* t1 = newhead1;
        ListNode* t2 = newhead2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;
        while(t1 != NULL || t2 != NULL || carry != 0) {
            int sum = carry;
            if(t1 != NULL) {
                sum += t1->val;
                t1 = t1->next;
            }
            if(t2 != NULL) {
                sum += t2->val;
                t2 = t2->next;
            }
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(digit);
            curr->next = temp;
            curr = temp;
        }
        ListNode* result = reverse(dummyNode->next);
        return result;
    }
};