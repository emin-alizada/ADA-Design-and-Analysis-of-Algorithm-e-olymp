// 10046 - LinkedList Reverse

ListNode* reverse(ListNode *head) {
    ListNode* prev= nullptr;
    ListNode* next;

    while(head)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }

    return prev;
}