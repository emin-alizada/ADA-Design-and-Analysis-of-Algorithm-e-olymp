ListNode* DeleteFirstElement(ListNode* head, int element) {
    ListNode *p = head;
    ListNode *q = head;

    if(p->val == element) {
        head = p->next;
        return head;
    }

    while (p->next) {
        q=p;
        p=p->next;

        if(p->val == element) {
            if(p->next) {
                q->next = p->next;
            } else {
                q->next = nullptr;
            }
            break;
        }
    }

    return head;
}
