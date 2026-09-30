#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to reverse doubly linked list
Node* reverseDoubly(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;          // purana prev save karo
        current->prev = current->next; // prev ko next bana do
        current->next = temp;          // next ko purana prev bana do
        current = current->prev;       // aglay node par jao
    }
    if (temp != nullptr) {
        head = temp->prev;             // new head set karo
    }
    return head;
}

// Helper function to print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // List create: 1 <-> 2 <-> 3
    Node* head = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{2, head, nullptr};
    head->next = n2;
    Node* n3 = new Node{3, n2, nullptr};
    n2->next = n3;

    cout << "Original List: ";
    printList(head);

    head = reverseDoubly(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}

