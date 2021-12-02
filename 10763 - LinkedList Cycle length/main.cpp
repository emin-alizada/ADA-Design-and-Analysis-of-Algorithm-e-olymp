int CycleLength(ListNode* head)
{
    ListNode *p = head;
    ListNode *q = head;

    if (head == nullptr) return -1;

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

        while (p != q) {
            p = p->next;
            q = q->next;
        }

        int count = 1;
        p = p->next;

        while (p != q) {
            p = p->next;
            count++;
        }

        return count;
    } else {
        return -1;
    }
}
