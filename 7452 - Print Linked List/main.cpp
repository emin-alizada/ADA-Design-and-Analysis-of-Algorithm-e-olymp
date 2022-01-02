#include <iostream>

using namespace std;

class Node {

public:
    int data;
    Node *next;
    Node() : next(NULL) {};
    Node(int data, Node *next = NULL) : data(data), next(next) {};
};

class List {

public:

    Node *head, *tail;

    List() : head(NULL), tail(NULL) {};

    void addToTail(int val) {
        if (tail != NULL) // list is not empty
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        else head = tail = new Node(val);
    }

    void Print() {
        Node *head = this->head;
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }

    void PrintReverse() {
        ReversePrinter(this->head);
    }

    void ReversePrinter(Node *head)
    {
        if (head == NULL)
            return;

        ReversePrinter(head->next);

        cout << head->data << " ";
    }

};

int main() {
    int n, temp;
    cin >> n;

    List l = List();

    for (int i = 0; i < n; ++i) {
        cin >> temp;
        l.addToTail(temp);
    }

    l.Print();
    l.PrintReverse();

    return 0;
}
