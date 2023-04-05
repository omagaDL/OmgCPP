#include <iostream>
using namespace std;

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
  if (list_ptr == nullptr || prev_ptr == nullptr) {
    return list_ptr;
  }
  if (list_ptr->size == 0) {
    push_back(list_ptr, new_key);
    return list_ptr;
  }

  Node* after_ptr = prev_ptr->next;

  if (after_ptr == list_ptr->NIL) {
    push_back(list_ptr, new_key);
    return list_ptr;
  }
  if (prev_ptr == list_ptr->NIL) {
    Node* new_node = new Node;
    new_node->key = new_key;
    new_node->prev = list_ptr->NIL;
    new_node->next = list_ptr->HEAD;
    list_ptr->HEAD->prev = new_node;
    list_ptr->HEAD = new_node;
    ++(list_ptr->size);
    return list_ptr;
  }
  Node* new_node = new Node;
  new_node->key = new_key;
  new_node->prev = prev_ptr;
  new_node->next = after_ptr;
  prev_ptr->next = new_node;
  after_ptr->prev = new_node;
  ++(list_ptr->size);
  return list_ptr;
}

void print_list(const List* list_ptr) {
    if (list_ptr == nullptr || list_ptr->HEAD == list_ptr->NIL) {
        return;
    }
    Node* curr_node = list_ptr->HEAD;
    while (curr_node != list_ptr->NIL) {
        cout << curr_node->key << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}

void clear_list(List* list_ptr) {
  if (list_ptr == nullptr) {
    return;
  }
  Node* iterator = list_ptr->HEAD;
  while (iterator != list_ptr->NIL) {
    Node* next_iterator = iterator->next;
    delete iterator;
    iterator = next_iterator;
  }
  list_ptr->HEAD = list_ptr->NIL;
  list_ptr->TAIL = list_ptr->NIL;
  list_ptr->size = 0;
}

void destroy_list(List* list_ptr) {
  if (list_ptr == nullptr) {
    return;
  }
  Node* iterator = list_ptr->HEAD;
  while (iterator != list_ptr->NIL) {
    Node* next_iterator = iterator->next;
    delete iterator;
    iterator = next_iterator;
  }
  delete list_ptr->NIL;
  delete list_ptr;
}

Node* find_key(List* list_ptr, int key) {
  if (list_ptr == nullptr) {
    return nullptr;
  }
  Node* iterator = list_ptr->HEAD;
  while (iterator != list_ptr->NIL) {
    if (iterator->key == key) {
      break;
    }
    iterator = iterator->next;
  }
  return iterator;
}

void remove_key(List* list_ptr, int key) {
  if (list_ptr == nullptr) {
    return;
  }
  Node* iterator = list_ptr->HEAD;
  while (iterator != list_ptr->NIL) {
    if (iterator->key == key) {
      list_ptr->size -= 1;
      if (iterator == list_ptr->HEAD) {
        Node* head = list_ptr->HEAD;
        list_ptr->HEAD = head->next;
        list_ptr->HEAD->prev = list_ptr->NIL;
        delete head;
        return;
      }
      if (iterator == list_ptr->TAIL) {
        Node* tail = list_ptr->TAIL;
        list_ptr->TAIL = tail->prev;
        list_ptr->TAIL->next = list_ptr->NIL;
        delete tail;
        return;
      }
      iterator->prev->next = iterator->next;
      iterator->next->prev = iterator->prev;
      delete iterator;
      return;
    }
    iterator = iterator->next;
  }
}