//
// Created by Emin Alizade on 02.10.21.
//


//Whole code which might not pass in e-olymp, but here is for understanding whole picture
#include <iostream>

using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    ListNode *head, *tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    };

    // check if list is empty
    bool Empty() {
        return head == NULL;
    }

    // add val to the head of the list
    void addFirst(int val) {
        if (this->Empty()) {
            head = tail = new ListNode(val);
        } else {
            ListNode *temp = new ListNode(val);
            temp->next = head->next;
            head = temp;
        }
    }

    // add val to the tail of the list
    void addLast(int val) {
        if (this->Empty()) {
            head = tail = new ListNode(val);
        } else {
            tail->next = new ListNode(val);
            tail = tail->next;
        }
    }

    // delete first element of the list, return true is removed successfully
    bool removeFirst() {
        if (this->Empty()) {
            return false;
        } else if (head == tail) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        return true;
    }

    // delete last element of the list, return true is removed successfully
    bool removeLast() {
        if (this->Empty()) {
            return false;
        } else if (head == tail) {
            head = tail = NULL;
        } else {
            ListNode *temp = head;

            while (temp->next != tail) {
                temp = temp->next;
            }

            temp->next = NULL;
            tail = temp;
        }
        return true;
    }

    // return the size of the list
    int size(ListNode *l) {
        int count = 0;
        ListNode *temp = l;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // print values of the list in one line
    void Print() {
        ListNode *temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // print values of the list in one line in reverse order
    void PrintReverse(ListNode *head) {
        if (head == NULL)
            return;

        PrintReverse(head->next);

        cout << head->data << " ";
    }

//    print the sum of the nodes of linked lst
    int sum() {
        ListNode *temp = head;
        int sum = 0;

        while (temp != NULL) {
            sum += temp->data;
            temp = temp->next;
        }

        return sum;
    }

//    detect where cycle start or return null
    ListNode *detectCycleStart(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;

        if (head == NULL) return NULL;

        bool flag = false;
        while (q->next && q->next->next) {
            q = q->next->next;
            p = p->next;

            if (q == p) {
                flag = true;
                break;
            }
        }

        if (flag) {
            p = head;

            while (p != q) {
                p = p->next;
                q = q->next;
            }

            return p;
        } else {
            return NULL;
        }
    }

    ListNode *merge(ListNode *l1, ListNode *l2) {
        ListNode *temp = new ListNode(0);
        ListNode *res = new ListNode(0);

        bool isFirst = true;
        while (l1 && l2) {
            if (l1->data > l2->data) {
                temp->next = new ListNode(l2->data);
                l2 = l2->next;
            } else {
                temp->next = new ListNode(l1->data);
                l1 = l1->next;
            }

            if (isFirst) {
                res = temp->next;
                isFirst = false;
            }

            temp = temp->next;
        }

        while (l1) {
            temp->next = new ListNode(l1->data);
            l1 = l1->next;
            temp = temp->next;
        }

        while (l2) {
            temp->next = new ListNode(l2->data);
            l2 = l2->next;
            temp = temp->next;
        }

        return res;
    }

    ListNode *findIntersectingNode(ListNode *l1, ListNode *l2) {
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
};

int main() {
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(7);
    l1->next->next->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(1);
//    l2->next = new ListNode(3);
//    l2->next->next = new ListNode(5);
//    l2->next->next->next = new ListNode(7);
//    l2->next->next->next->next = new ListNode(9);

    LinkedList *list = new LinkedList();
    list->head = list->merge(l1, l2);
    list->Print();

    return 0;
}