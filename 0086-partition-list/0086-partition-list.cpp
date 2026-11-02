class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummy1 = new ListNode(-1);
        ListNode* dummy2 = new ListNode(-1);
        ListNode* head1 = dummy1;
        ListNode* head2 = dummy2;
        ListNode* temp = head;
        while(temp != NULL) {
            if(temp->val < x) {
                head1->next = temp;
                head1 = head1->next;
            }
            else {
                head2->next = temp;
                head2 = head2->next;
            }
            temp = temp->next;
        }
        head2->next = NULL;
        head1->next = dummy2->next;
        return dummy1->next;
    }
};