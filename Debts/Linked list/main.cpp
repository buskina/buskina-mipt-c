#include <iostream>

struct Node {
    int value;
    Node* next;
    Node* prev;
};

struct List {
    unsigned size_n = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

// adds new node with value new_val to the end
void my_push_back (int new_val) {
    Node* last = new Node();
    last->value = new_val;
    if (head == nullptr) {
        head = last;
        size_n = 1;
    }
    if (tail == nullptr) {
        tail = last;
    } else {
        tail->next = last;
        last->prev = tail;
        tail = last;
        size_n++;
    }
}

// add new node with value new_val to the front
void my_push_front (int new_val) {
    Node* first = new Node();
    (*first).value = new_val;
    if (head == nullptr) {
        head = first;
        size_n = 1;
    }
    if (tail == nullptr) {
        tail = first;
    } else {
        first->next = head;
        head->prev = first;
        head = first;
        size_n++;
    }
}

// add new node with value new_val in front of i‘th node
void my_insert (int new_val, int i) {
    if (i < 0 || i > size_n - 1)
        return;
    Node* ist = new Node();
    ist->value = new_val;
    if (i == 0) {
        ist->next = head;
        head->prev = ist;
        head = ist;
        size_n++;
        return;
    }
    Node* curr = head;
    int j = 0;
    while (j < i - 1) {
        curr = curr->next;
        j++;
    }
    ist->next = curr->next;
    curr->next = ist;
    ist->next->prev = ist;
    ist->prev = curr;
    size_n++;
    return;
}

// get the last element value and delete last element
int my_pop_back () {
    if (tail == nullptr) {
        return 0;
    }
    if (size_n == 1) {
        int ans = head -> value;
        head = tail = nullptr;
        size_n = 0;
        return ans;
    }
    Node* curr = tail -> prev;
    int ans = tail->value;
    delete tail;
    tail = curr;
    tail->next = nullptr;
    size_n--;
    return ans;
}

// get the front element value and delete last element

int my_pop_front () {
    if (head == nullptr) {
        return 0;
    }
    Node* curr = head->next;
    int ans = head->value;
    curr->prev = nullptr;
    delete head;
    head = curr;
    if (size_n == 1) {
        delete tail;
    }
    size_n--;
    return ans;
}

// delete i‘th element
int my_remove (unsigned idx) {
    if (idx < 0 || idx > size_n - 1)
        return 0;
    if (idx == 0) {
        Node *tmp = head;
        int ans = tmp->value;
        head = head->next;
        head->prev = nullptr;
        delete tmp;
        size_n--;
        return ans;
    }
    Node* curr = head;
    unsigned j = 0;
    while (j < idx - 1) {
        curr = curr->next;
        j++;}
    Node* tmp = curr->next;
    curr->next = tmp->next;
    curr->next->prev = curr;
    int ans = tmp->value;
    delete tmp;
    size_n--;
    return ans;
}

// get the length of the list
unsigned length () {
    if (head == nullptr) {
        return 0;
    }
    return size_n;
}

// get the i‘th element by index
int get (unsigned idx) {
    if (idx < 0 || idx > size_n - 1)
        return 0;
    if (idx == 0) {
        return head->value;
    }
    Node* curr = head;
    unsigned j = 0;
    while (j < idx) {
        curr = curr->next;
        j++;}
    return curr->value;
}

// clear all elements of the list
void my_clear () {
    if (!size_n) {
        return;
    }
    while (head != tail) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
    delete head;
    size_n = 0;
    head = tail = nullptr;
    return;
}

// print all elements of the list
void print () {
    if (head == nullptr) {
        std::cout << "list is empty \n";
        return;
    }
    Node* curr = head;
    while (curr != tail) {
        std::cout << curr->value << " ";
        curr = curr->next;
    }
    std::cout << tail->value << "\n";
}
};

int main()
{
    List test;
    int n, a, b;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        test.my_push_back(a);
    }
    test.print();
    std::cin >> b;
    test.my_insert(b, 0);
    test.print();
    std::cout << "pop back: " << test.my_pop_back() << "\n";
    std::cout << "pop front: " << test.my_pop_front() << "\n";
    test.print();
    std::cout << "length: " << test.length() << "\n";
    std::cout << "remove: " << test.my_remove(1) << "\n";
    std::cout << "get: " << test.get(1) << "\n";
    test.print();
    test.my_clear();
    return 0;
}
