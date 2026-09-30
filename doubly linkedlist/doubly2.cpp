#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to swap two nodes by values
Node* swapNodes(Node* head, int x, int y) {
    if (x == y) return head;

    Node* nodeX = nullptr;
    Node* nodeY = nullptr;
    Node* temp = head;

    // Search values
    while (temp != nullptr) {
        if (temp->data == x) nodeX = temp;
        if (temp->data == y) nodeY = temp;
        temp = temp->next;
    }

    if (nodeX == nullptr || nodeY == nullptr) {
        cout << "Value not found!" << endl;
        return head;
    }

    // Neighbors update
    if (nodeX->prev != nullptr) nodeX->prev->next = nodeY;
    if (nodeY->prev != nullptr) nodeY->prev->next = nodeX;

    if (nodeX->next != nullptr) nodeX->next->prev = nodeY;
    if (nodeY->next != nullptr) nodeY->next->prev = nodeX;

    // Swap links
    swap(nodeX->prev, nodeY->prev);
    swap(nodeX->next, nodeY->next);

    // Head update
    if (head == nodeX) head = nodeY;
    else if (head == nodeY) head = nodeX;

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
    // List create: 1 <-> 2 <-> 3 <-> 4
    Node* head = new Node{1, nullptr, nullptr};
    Node* n2 = new Node{2, head, nullptr};
    head->next = n2;
    Node* n3 = new Node{3, n2, nullptr};
    n2->next = n3;
    Node* n4 = new Node{4, n3, nullptr};
    n3->next = n4;

    cout << "Original List: ";
    printList(head);

    head = swapNodes(head, 2, 4);

    cout << "After Swapping 2 and 4: ";
    printList(head);

    return 0;
}

