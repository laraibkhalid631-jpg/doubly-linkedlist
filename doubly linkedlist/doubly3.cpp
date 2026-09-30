#include <iostream>
using namespace std;

// Singly linked list node
struct SNode {
    int data;
    SNode* next;
};

// Doubly linked list node
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

// Function to convert singly list into doubly list
DNode* convertToDoubly(SNode* headS) {
    if (headS == nullptr) return nullptr;

    // Pehla node doubly list ka banao
    DNode* headD = new DNode{headS->data, nullptr, nullptr};
    DNode* currentD = headD;
    SNode* currentS = headS->next;

    // Har singly node ko doubly node mein badalna
    while (currentS != nullptr) {
        DNode* newNode = new DNode{currentS->data, currentD, nullptr};
        currentD->next = newNode;   // forward link
        currentD = newNode;         // move to new node
        currentS = currentS->next;  // singly list mein agay jao
    }
    return headD;
}

// Helper function to print doubly list
void printDoubly(DNode* head) {
    DNode* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Singly linked list create: 10 -> 20 -> 30
    SNode* sHead = new SNode{10, nullptr};
    sHead->next = new SNode{20, nullptr};
    sHead->next->next = new SNode{30, nullptr};

    cout << "Singly Linked List: 10 20 30" << endl;

    // Convert singly to doubly
    DNode* dHead = convertToDoubly(sHead);

    cout << "Converted Doubly Linked List: ";
    printDoubly(dHead);

    return 0;
}

