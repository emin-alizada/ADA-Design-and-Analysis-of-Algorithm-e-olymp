////
//// Created by Emin Alizade on 02.12.21.
////

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
        head = nullptr;
        tail = nullptr;
    };

    // check if list is empty
    bool Empty() {
        return head == nullptr;
    }

    // add val to the head of the list
    void addFirst(int val) {
        if (this->Empty()) {
            head = tail = new ListNode(val);
        } else {
            ListNode *temp = new ListNode(val);
            temp->next = head;
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
            head = tail = nullptr;
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
            head = tail = nullptr;
        } else {
            ListNode *temp = head;

            while (temp->next != tail) {
                temp = temp->next;
            }

            temp->next = nullptr;
            tail = temp;
        }
        return true;
    }

    // return the size of the list
    int size() {
        int count = 0;
        ListNode *temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // print values of the list in one line
    void Print() {
        ListNode *temp = head;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int sumOfOdd() {
        ListNode *temp = head;
        int sum = 0;

        while (temp != nullptr) {
            if (temp->data % 2 == 1) {
                sum += temp->data;
            }
            temp = temp->next;
        }

        return sum;
    }

    int numberOfEvenElements() {
        ListNode *temp = head;
        int count = 0;

        while (temp != nullptr) {
            if (temp->data % 2 == 0) {
                count++;
            }
            temp = temp->next;
        }

        return count;
    }
};


int main() {
    int temp;
    string o, o1;
    LinkedList *list = new LinkedList();

    while (cin >> o >> o1) {
        string op = o + " " + o1;

        if (op == "push front") {
            cin >> temp;

            list->addFirst(temp);
        }

        if (op == "push back") {
            cin >> temp;

            list->addLast(temp);
        }

        if (op == "pop front") {
            list->removeFirst();
        }

        if (op == "pop back") {
            list->removeLast();
        }
    }

    cout << list->numberOfEvenElements();

    return 0;
}
