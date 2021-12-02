// 10802 - LinkedList Distance to Cycle
int DistanceToCycle(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;

    if (head == NULL) return -1;

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
        int count = 0;
        p = head;

        while (p != q) {
            p = p->next;
            q = q->next;
            count++;
        }

        return count;
    } else {
        return -1;
    }
}
