#include <iostream>

using namespace std;

struct Node {
    Node* next;
    int value;

    Node() : next(0), value(0) {}
    ~Node() {}
};

class LinkedList {
    private:
        Node* head;
        int size;

    public:
        LinkedList() : head(0), size(0) {}
        ~LinkedList() {
            while(head) {
                Node* tmp = head->next;
                delete head;
                head = tmp;
            }
        }

        void add(const int& value) {
            Node* newNode = new Node();
            newNode->value = value;
            newNode->next = head;
            head = newNode;
            ++size;
        }

        inline Node* getHead() const { return head; }
        inline int getSize() const { return size; }

        void show() const {
            Node* tmp = head;
            while(tmp) {
                cout << tmp->value;
                if(tmp->next) {
                    cout << ", ";
                }
                tmp = tmp->next;
            }
            cout << endl;
        }
};

Node* doZip(Node* head, Node* lastN) {
    if(!lastN) {
        return head;
    }

    Node* currentN = doZip(head, lastN->next);
    if(!currentN) {
        return 0;
    }
    if(currentN == lastN || currentN->next == lastN) {
        lastN->next = 0;
        return 0;
    }

    Node* nextN = currentN->next;
    currentN->next = lastN;
    lastN->next = nextN;

    return nextN;
}

void zip(const LinkedList& ll) {
    doZip(ll.getHead(), ll.getHead());
}

int main() {
    LinkedList ll;
    ll.add(15);
    ll.add(14);
    ll.add(13);
    ll.add(12);
    ll.add(11);
    ll.add(10);
    ll.add(9);
    ll.add(8);
    ll.add(7);
    ll.add(6);
    ll.add(5);
    ll.add(4);
    ll.add(3);
    ll.add(2);
    ll.add(1);
    ll.add(0);
    ll.show();

    zip(ll);
    ll.show();
    return 0;
}
