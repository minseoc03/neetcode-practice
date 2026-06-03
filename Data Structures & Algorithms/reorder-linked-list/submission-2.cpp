class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {      // slow가 첫 절반 끝에
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second_half = slow->next;
        slow->next = nullptr;                          // ← 절단 (버그 2)

        ListNode* curr = second_half;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;                                // ← nxt 사용 (버그 1)
        }
        second_half = prev;

        ListNode dummy(0);
        ListNode* merge = &dummy;
        ListNode* cur1 = head;
        ListNode* cur2 = second_half;
        while (cur1 && cur2) {
            merge->next = cur1; cur1 = cur1->next; merge = merge->next;
            merge->next = cur2; cur2 = cur2->next; merge = merge->next;
        }
        if (cur1) merge->next = cur1;
        if (cur2) merge->next = cur2;
    }
};