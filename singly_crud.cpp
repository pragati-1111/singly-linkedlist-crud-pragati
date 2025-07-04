#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int data) {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
        cout << "Inserted " << data << " at the beginning." << endl;
    }

    void search(int key) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == key) {
                cout << "Key found: " << key << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "Key not found: " << key << endl;
    }

    void deleteNode(int key) {
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            cout << "Node with key " << key << " not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = head->next;
        } else {
            prev->next = curr->next;
        }

        delete curr;
        cout << "Deleted node with key: " << key << endl;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* temp = nullptr;

        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;
        cout << "List reversed." << endl;
    }

    void display() {
        Node* curr = head;
        cout << "List: ";
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, data;

    do {
        cout << endl << "--- Linked List Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Search" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Reverse List" << endl;
        cout << "5. Display List" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                list.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to search: ";
                cin >> data;
                list.search(data);
                break;
            case 3:
                cout << "Enter data to delete: ";
                cin >> data;
                list.deleteNode(data);
                break;
            case 4:
                list.reverse();
                break;
            case 5:
                list.display();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
