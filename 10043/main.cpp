//ListNode* detectCycle(ListNode *head)
//{
//    ListNode *p = head;
//    ListNode *q = head;
//
//    if (head == NULL) return NULL;
//
//    bool flag = false;
//    while (q->next && q->next->next) {
//        q = q->next->next;
//        p = p->next;
//
//        if (q == p) {
//            flag = true;
//            break;
//        }
//    }
//
//    if (flag) {
//        p = head;
//
//        while (p != q) {
//            p = p->next;
//            q = q->next;
//        }
//
//        return p;
//    } else {
//        return NULL;
//    }
//}