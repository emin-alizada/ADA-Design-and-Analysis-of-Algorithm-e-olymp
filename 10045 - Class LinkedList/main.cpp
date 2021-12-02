#include <stdio.h>

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data) : data(data), next(NULL) {}
};

class LinkedList
{
public:
    ListNode *head, *tail;
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    bool Empty()
    {
        return head == NULL;
    }

    void addFirst(int val)
    {
        if (tail == NULL) // list is empty
            head = tail = new ListNode(val);
        else
        {
            ListNode *temp = new ListNode(val);
            temp->next = head;
            head = temp;
        }
    }

    void addLast(int val)
    {
        if (tail != NULL) // list is not empty
        {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
        else head = tail = new ListNode(val);
    }

    bool removeFirst()
    {
        if (Empty()) return false;
        if (head == tail) // only one node in a list
            head = tail = NULL;
        else head = head->next;
        return true;
    }

    bool removeLast()
    {
        if (Empty()) return false;
        if (head == tail) // only one node in a list
        {
            head = tail = NULL;
        }
        else // if more than one node in the list
        {
            ListNode *temp;
            // find the predecessor of  tail
            for (temp = head; temp->next != tail; temp = temp->next);
            tail = temp; // the predecessor of  tail becomes tail
            tail->next = NULL;
        }
        return true;
    }

    void Print()
    {
        ListNode *head = this->head;
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }

    int size()
    {
        int cnt = 0;
        ListNode *head = this->head;
        while (head != NULL)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
};

int i, n, x, cyc;
ListNode *temp;

int main(void)
{
    scanf("%d", &n);
    LinkedList *list = new LinkedList();
    if (list->Empty()) printf("Empty\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        list->addFirst(x);
    }

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        list->addLast(x);
    }

    list->removeFirst(); list->removeLast();
    list->removeFirst();

    list->Print();
    printf("%d\n",list->size());

    return 0;
}
