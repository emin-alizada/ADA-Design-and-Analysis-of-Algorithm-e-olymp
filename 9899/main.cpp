int size() {
    int count = 0;
    ListNode *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}