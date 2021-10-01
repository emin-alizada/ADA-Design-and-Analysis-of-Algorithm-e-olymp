////
//// Created by Emin Alizade on 01.10.21.
////
//
//#include <iostream>
//
//using namespace std;
//
//class ListNode {
//public:
//    int data;
//    ListNode *next;
//
//    ListNode(int data) {
//        this->data = data;
//        this->next = nullptr;
//    }
//};
//
//class LinkedList {
//public:
//    ListNode *head, *tail;
//
//    LinkedList() {
//        head = NULL;
//        tail = NULL;
//    };
//
//    // check if list is empty
//    bool Empty() {
//        return head == NULL;
//    }
//
//    // add val to the head of the list
//    void addFirst(int val) {
//        if (this->Empty()) {
//            head = tail = new ListNode(val);
//        } else {
//            ListNode *temp = new ListNode(val);
//            temp->next = head->next;
//            head = temp;
//        }
//    }
//
//    // add val to the tail of the list
//    void addLast(int val) {
//        if (this->Empty()) {
//            head = tail = new ListNode(val);
//        } else {
//            tail->next = new ListNode(val);
//            tail = tail->next;
//        }
//    }
//
//    // delete first element of the list, return true is removed successfully
//    bool removeFirst() {
//        if (this->Empty()) {
//            return false;
//        } else if (head == tail) {
//            head = tail = NULL;
//        } else {
//            head = head->next;
//        }
//        return true;
//    }
//
//    // delete last element of the list, return true is removed successfully
//    bool removeLast() {
//        if (this->Empty()) {
//            return false;
//        } else if (head == tail) {
//            head = tail = NULL;
//        } else {
//            ListNode *temp = head;
//
//            while (temp->next != tail) {
//                temp = temp->next;
//            }
//
//            temp->next = NULL;
//            tail = temp;
//        }
//        return true;
//    }
//
//    // return the size of the list
//    int size() {
//        int count = 0;
//        ListNode *temp = head;
//
//        while (temp != NULL) {
//            count++;
//            temp = temp->next;
//        }
//
//        return count;
//    }
//
//    // print values of the list in one line
//    void Print() {
//        ListNode *temp = head;
//
//        while (temp != NULL) {
//            cout << temp->data << " ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
//};
//
//int i, n, x, cyc;
//ListNode *temp;
//
//int main() {
//    scanf("%d", &n);
//    LinkedList *list = new LinkedList();
//    if (list->Empty()) printf("Empty\n");
//
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &x);
//        list->addFirst(x);
//    }
//
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &x);
//        list->addLast(x);
//    }
//
//    list->removeFirst(); list->removeLast();
//    list->removeFirst();
//
//    list->Print();
//    printf("%d\n",list->size());
//
//    return 0;
//}
