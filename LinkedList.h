//
// Created by Dariusz Doliwa on 12/11/2025.
//
template <typename T>
struct Node {
    T data;
    Node* next;
    Node (T data, Node* next) {
        this->data=data;
        this->next=next;
    }
};

template <typename T>
class SingleLinkedList {
    Node <T> * head;
public:
    SingleLinkedList() {
        head=nullptr;
    }
    void addNodeAtFront(T data) {
        Node<T>* newNode;
        newNode = new Node<T>(data, head);
        head=newNode;
    }
    void addNodeAtEnd(T data) {
        Node<T>* newNode;
        newNode=new Node <T> (data, nullptr);
        if (head==nullptr) {
            head=newNode;
            return;
        }
        Node<T>* temp=head;
        while (temp->next!=nullptr) {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void print() {
        Node<T>* temp=head;
        while (temp!= nullptr) {
            std::cout<<temp->data<<" ";
            temp=temp->next;
        }
        std::cout<<std::endl;
    }
    void removeFromFront() {
        if (head==nullptr) {
            std::cout<<"List is empty - is not possible to remove element";
            return;
        }
        Node <T>* temp=head;
        head=head->next;
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

};


