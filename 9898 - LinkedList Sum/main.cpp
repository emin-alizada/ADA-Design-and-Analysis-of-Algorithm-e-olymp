int sum(ListNode *head)
{
    ListNode *temp = head;
    int sum = 0;

    while (temp != NULL) {
        sum += temp->val;
        temp = temp->next;
    }

    return sum;
}

// Passing code on e-olymp