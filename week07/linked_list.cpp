#include <iostream>

struct Node {
    int key = 0;
    Node* next = nullptr;
};

void push_front(Node*& head_ref, int new_key) {
    Node* newNode = new Node();
    newNode->key = new_key;
    newNode->next = head_ref;
    head_ref = newNode;
}

void push_back(Node*& head_ref, int new_key) {
    Node* newNode = new Node();
    newNode->key = new_key;
    if (head_ref == nullptr) {
        head_ref = newNode;
        return;
    }
    Node* last = head_ref;
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;
}

void insert_after(Node*& prev_ref, int new_key) {
    if (prev_ref == nullptr){
        return;
    }
    Node* newNode = new Node;
    newNode->key = new_key;
    newNode->next = prev_ref->next;
    prev_ref->next = newNode; 
}

void destroy_list(Node*& head_ref) {
    Node* cur_node = head_ref;
    while (cur_node != nullptr) {
        Node* next_node = cur_node->next;
        delete cur_node;
        cur_node = next_node;
    }
    head_ref = nullptr;
}