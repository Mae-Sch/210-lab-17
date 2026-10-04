#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};
// I'm passing by reference because it also the functions more straightforward to use IMO, 
// when you use "addNodeFront", you want it to add the node, not require an = beforehand
// using reference also prevents duplicate nodes being created
void addNodeFront(Node *&, float);
bool addNodeTail(Node *&);
bool deleteNode(Node *&);
void insertNode(Node *&);
void deleteList(Node *&);

void output(Node *);

void addNodeFront(Node *& head, float val) {
    Node *newVal = new Node;
    if (!head) {
            head = newVal;
            newVal->next = nullptr;
            newVal->value = val;
        }
        else {
            newVal->next = head;
            newVal->value = val;
            head = newVal;
        }
}

bool deleteNode(Node *& head) {
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    Node *current = head;
    Node *prev = nullptr;  // start prev as nullptr to detect head deletion

    for (int i = 0; i < (entry - 1); i++) {
        prev = current;
        current = current->next;
        // avoids segmentation fault if entered number is greater than list length
        if (current == nullptr)
            return false;
    }

    // at this point, delete current and reroute pointers
    if (current) {
        if (prev == nullptr) {
            // deleting the head node
            head = current->next;
        } else {
            prev->next = current->next;
        }
        delete current;
        current = nullptr;
    }
    return true;
} 

void insertNode(Node *& head) {
    Node *current = head;
    Node *prev = nullptr;
    int entry;
    int count = 1;

    cout << "After which node to insert 10000? " << endl;
    current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = nullptr;  // reset prev to nullptr for same reason

    for (int i = 0; i < entry; i++) {
        prev = current;
        current = current->next;
    }

    // at this point, insert a node between prev and current
    Node *newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;

    if (prev == nullptr) {
        // inserting before the head
        head = newnode;
    } else {
        prev->next = newnode;
    }
    output(head);
}

void deleteList(Node *& head) {
    Node *current = head;
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
    output(head);
}

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        addNodeFront(head, tmp_val);
    }
    output(head);
    deleteNode(head);
    output(head);

    //////////////////////kept temporarily to make main() below work
    Node *current = head;
    Node *prev = nullptr;
    int entry;

    insertNode(head);
    deleteList(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}