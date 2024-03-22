#include <iostream>
//серед чисел знайти якесь
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

int countElementsWithValue(Node* head, int value) {
    int count = 0;
    while (head) {
        if (head->data == value) {
            count++;
        }
        head = head->next;
    }
    return count;
}
//хочу найти 5
int main() {
    Node* head = nullptr;
    insert(head, 5);
    insert(head, 2);
    insert(head, 3);
    insert(head, 1);
    insert(head, 4);
    insert(head, 5);
    insert(head, 1);
    insert(head, 6);
    insert(head, 5);
    insert(head, 8);

    std::cout << "List: ";
    printList(head);

    int valueToFind = 8;
    int count = countElementsWithValue(head, valueToFind);
    std::cout << "Number of elements with value " << valueToFind << ": " << count << std::endl;

    return 0;
}