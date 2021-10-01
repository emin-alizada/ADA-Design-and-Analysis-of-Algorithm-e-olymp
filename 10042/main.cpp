//int hasCycle(ListNode *head)
//{
//    if (head == NULL) return 0;
//    ListNode* p = head;
//    ListNode* q = head;
//    while (q->next && q->next->next)
//    {
//        p = p->next;
//        q = q->next->next;
//        if (p == q) return 1;
//    }
//    return 0;
//}