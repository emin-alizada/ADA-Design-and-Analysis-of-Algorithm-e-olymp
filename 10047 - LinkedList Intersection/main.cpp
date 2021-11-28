int size(ListNode *l) {
    int count = 0;
    ListNode *temp = l;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    return count;
}

ListNode *intersection(ListNode *l1, ListNode *l2)
{
    int sizeL1 = size(l1);
    int sizeL2 = size(l2);

    if (sizeL1 > sizeL2) {
        int dif = sizeL1 - sizeL2;

        while (dif--) {
            l1 = l1->next;
        }
    } else {
        int dif = sizeL2 - sizeL1;

        while (dif--) {
            l2 = l2->next;
        }
    }

    while (l1 != l2){
        l1 = l1->next;
        l2 = l2->next;
    }

    return l1;
}
