ListNode* merge(ListNode *l1, ListNode *l2)
{
//    Declaringtwo variables, res which is going to be returned after everything and temp to operate on
    ListNode *temp = new ListNode(0);
    ListNode *res = new ListNode(0);
    res = temp;

//    Adding to temp from both linked list elements that are smaller
    while (l1 && l2) {
        if (l1->val > l2->val) {
            temp->next = new ListNode(l2->val);
            l2 = l2->next;
        } else {
            temp->next = new ListNode(l1->val);
            l1 = l1->next;
        }

        temp = temp->next;
    }

//    adding the rest of list 1
    while (l1) {
        temp->next = new ListNode(l1->val);
        l1 = l1->next;
        temp = temp->next;
    }

    //    adding the rest of list 2
    while (l2) {
        temp->next = new ListNode(l2->val);
        l2 = l2->next;
        temp = temp->next;
    }

    return res->next;
}