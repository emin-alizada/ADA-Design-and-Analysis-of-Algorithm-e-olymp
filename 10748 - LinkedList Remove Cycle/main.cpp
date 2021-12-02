ListNode* removeCycle(ListNode* head)
{
    ListNode *p = head;
    ListNode *q = head;

    if (head == nullptr) return head;

    bool flag = false;
    while (q->next && q->next->next) {
        q = q->next->next;
        p = p->next;

        if (q == p) {
            flag = true;
            break;
        }
    }

    if (flag) {
        p = head;

        while (p->next != q->next) {
            p = p->next;
            q = q->next;
        }

        q->next = nullptr;

    }

    return head;
}
