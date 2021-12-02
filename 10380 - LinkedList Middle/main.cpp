ListNode* MiddleElement(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    ListNode *temp1 = head;

    for (int i = 1; i < (count+1)/2 ; ++i) {
        temp1 = temp1->next;
    }

    return temp1;
}

