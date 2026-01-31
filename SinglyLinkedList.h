#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class SingleLinkedList {
    Node<T>* head;

public:
    SingleLinkedList() {
        head = nullptr;
    }

    void addNodeAtFront(T data) {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
    }

    void addNodeAtEnd(T data) {
        Node<T>* newNode = new Node<T>(data, nullptr);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void removeFromFront() {
        if (head == nullptr) {
            std::cout << "List is empty - is not possible to remove element";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void removeFromEnd() {
        if (head == nullptr) {
            std::cout << "List is empty - is not possible to remove element";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        Node<T>* last = temp->next;
        temp->next = nullptr;
        delete last;
    }

    void insertAtPosition(T value, int k) {
        if (k <= 0) {
            std::cout << "Position out of range.";
            return;
        }

        if (k == 1) {
            addNodeAtFront(value);
            return;
        }

        Node<T>* prev = head;
        int pos = 1;

        while (prev != nullptr && pos < k - 1) {
            prev = prev->next;
            pos++;
        }

        if (prev == nullptr) {
            std::cout << "Position out of range.";
            return;
        }

        Node<T>* newNode = new Node<T>(value, prev->next);
        prev->next = newNode;
    }

    void deleteAtPosition(int k) {
        if (k <= 0 || head == nullptr) {
            std::cout << "Unable to delete: position out of range.";
            return;
        }

        if (k == 1) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* prev = head;
        int pos = 1;

        while (prev != nullptr && pos < k - 1) {
            prev = prev->next;
            pos++;
        }

        if (prev == nullptr || prev->next == nullptr) {
            std::cout << "Unable to delete: position out of range.";
            return;
        }

        Node<T>* toDelete = prev->next;
        prev->next = toDelete->next;
        delete toDelete;
    }

    int length() {
        int counter = 0;
        Node<T>* temp = head;

        while (temp != nullptr) {
            counter++;
            temp = temp->next;
        }

        return counter;
    }

    Node<T>* pointerAtkthFromFront(int k) {
        if (k <= 0 || k > length()) {
            return nullptr;
        }

        Node<T>* temp = head;

        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }

        return temp;
    }

    T valueAtkthFromFront(int k) {
        Node<T>* temp = pointerAtkthFromFront(k);
        return temp->data;
    }

    int replaceAll(T a, T b) {
        int counter = 0;
        Node<T>* temp = head;

        while (temp != nullptr) {
            if (temp->data == a) {
                temp->data = b;
                counter++;
            }
            temp = temp->next;
        }

        return counter;
    }

    int countOccurrences(T value) {
        Node<T>* temp = head;
        int counter = 0;

        while (temp != nullptr) {
            if (temp->data == value) {
                counter++;
            }
            temp = temp->next;
        }

        return counter;
    }
};

#endif
