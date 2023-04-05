#include <iostream>

struct Node {
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = 0;
};

struct List {
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};


List* create_empty_list() {
    List* list = new List;
    Node* NIL = new Node; 

    NIL->next = NIL;
    NIL->prev = NIL;

    list->NIL = NIL;
    list->HEAD = NIL;
    list->TAIL = NIL; 

    return list;
}

List* push_front(List* list_ptr, int new_key) {
    if (list_ptr == nullptr) { 
        return nullptr;
    }

    Node* new_node = new Node; 
    new_node->key = new_key; 
    new_node->prev = list_ptr->NIL;
    new_node->next = list_ptr->HEAD;

    if (list_ptr->HEAD == list_ptr->NIL) { 
        list_ptr->TAIL = new_node;
    } else {
        list_ptr->HEAD->prev = new_node;
    }

    list_ptr->HEAD = new_node;
    return list_ptr;
}

List* push_back(List *list_ptr, int new_key){
    if (list_ptr == nullptr){
        return nullptr;
    } 
    list_ptr->size++;
    Node* tail = new Node;
    tail->next = list_ptr -> NIL;
    tail->prev = list_ptr -> TAIL;
    tail->key = new_key;
    list_ptr->TAIL->next = tail;
    list_ptr->TAIL = tail;
    if (list_ptr->TAIL->prev == list_ptr->NIL){
        list_ptr->HEAD = tail;
    }else if (list_ptr->TAIL->prev->prev == list_ptr->NIL) {
        list_ptr->HEAD = list_ptr->TAIL->prev;
    }
    return list_ptr;
}

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key) {
     if (list_ptr == nullptr){
        return nullptr;
    } 
    if (prev_ptr == nullptr && list_ptr != nullptr) {
        return push_back(list_ptr, new_key);
    }
    if (list_ptr == nullptr || prev_ptr == list_ptr->TAIL) {
        return nullptr;
    }
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->next = prev_ptr->next;
    prev_ptr->next = new_node;
    if (prev_ptr == list_ptr->TAIL) {
        list_ptr->TAIL = new_node;
    }
    return list_ptr;
}

