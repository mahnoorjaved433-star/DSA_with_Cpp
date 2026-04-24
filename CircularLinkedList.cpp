/* * Project: DSA with C++
 * Topic: Circular Linked List (All Insertions)
 * Author: [Hafiza Mahnoor]
 */

#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList {
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // 1. Insert at the beginning
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    // 2. Insert at the end
    void insertAtTail(int val) {
        if (head == NULL) {
            insertAtHead(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    // 3. Insert at a specific position
    void insertAtPosition(int pos, int val) {
        if (pos <= 1) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            // Check if we looped back to head (out of range)
            if (temp == head) {
                cout << "Position out of range!" << endl;
                return;
            }
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // 4. Show the whole list
    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(Back to Head)" << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Adding data
    cll.insertAtHead(10);
    cll.insertAtTail(30);
    cll.insertAtPosition(2, 20); // Adds 20 between 10 and 30

    cll.display();

    return 0;
}