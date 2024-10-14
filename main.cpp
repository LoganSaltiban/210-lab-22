#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_val(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void delete_pos(unsigned int position)
    {
        if (!head)
        {
            cout << "List is empty. Cannot Delete Node at Position: " << position << endl;
            return;
        }

        Node* traversalPtr = head;

        for (int i = 0, i < position && temp; i++) // 
        {
            traversalPtr = traversalPtr->next;
        }

        // Check if Traversal is null
        if (!traversalPtr)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Test Head and Tail cases
        if (traversalPtr->prev)
        {
            traversalPtr->prev->next = traversalPtr->next;
        } else // Head Case
        {
            head = traversalPtr->next;
        }

        if (traversalPtr->next)
        {
            traversalPtr->next->prev = traversalPtr->prev;
        } else // Tail Case
        {
            tail = traversalPtr->prev;
            traversalPtr->prev->next = nullptr;
        }

        // Finally delete the Node
        delete traversalPtr;
        traversalPtr = nullptr;

    }

    void pop_front()
    {
        // Test Case List is empty
        if (!head)
        {
            cout << "Empty List. Can't pop the front." << endl;
            return;
        }

        // Set Temp Equal to First Node
        Chair* temp = head;

        head = head->next; // Set Head to point to 2nd Heads Node
        // Set New Head Previous to Nullptr
        head->prev = nullptr;

        // Delete Temp to pop that Head Node
        delete temp;
        temp = nullptr;
    }

    void pop_back()
    {
        // Test case if List is empty
        if (!tail->prev && !head)
        {
            cout << "List is empty. Can't pop tail Node." << endl;
            return;
        }

        // Create temp and set to Node to delete
        Chair* temp = tail;
        // Set Tail to new Tail
        tail = tail->prev;
        // Set New Tail Next to nullptr 
        tail->next = nullptr;
        // Delete Old Tail
        delete temp;
        temp = nullptr;

    }



    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    DoublyLinkedList list;
    int size = rand() % (MAX_LS-MIN_LS+1) + MIN_LS;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "List after Deleting Node in Position (3): " << endl;
    list.delete_pos(3);
    list.print();
    
    cout << "List After Popping the Head Node:" << endl;
    list.pop_front();
    list.print();

    cout << "List after Popping the Tail Node:" << endl;
    list.pop_back();
    list.print();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
