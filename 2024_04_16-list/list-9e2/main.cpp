#define DEBUG 0
#include <iostream>

using namespace std;

struct Node {
    int inf = 0;
    Node *prev = nullptr, *next = nullptr;
    Node();
    Node(int n);
    Node(int n, Node *p_prev, Node *p_next);
    ~Node();
};

Node::Node() {
    if (DEBUG) cout << "Create node with inf = " << inf << endl;
}

Node::Node(int n) {
    inf = n;
    if (DEBUG) cout << "Create node with inf = " << inf << endl;
}

Node::Node(int n, Node *p_prev, Node *p_next) {
    inf = n;
    prev = p_prev;
    next = p_next;
    if (DEBUG) cout << "Create node with inf = " << inf << endl;
}

Node::~Node() {
    if (DEBUG) cout << "Destroy node with inf = " << inf << endl;
}

struct List{
    Node *head = nullptr, *tail = nullptr;
    int cnt = 0;
    List();
    ~List();

    bool AddFirst(int n);
    bool AddLast(int n);
    bool DelFirst();
    bool DelLast();
    Node* First();
    Node* Last();
    int FirstZ();
    int LastZ();
    bool Empty();
    void Clear();
    int Size();
    void Sort();
    void PrintHT();
    void PrintTH();
};

List::List() {
    if (DEBUG) cout << "Create list" << endl;
}

List::~List() {
    Clear();
    if (DEBUG) cout << "Delete list" << endl;
}

bool List::AddFirst(int n) {
    Node *p = new Node(n, nullptr, head);
    if (!p)
        return false;
    if (head)
        head -> prev  = p;
    head = p;
    if (!tail)
        tail = head;
    ++cnt;
    return true;
}

bool List::AddLast(int n) {
    Node *p = new Node(n, tail, nullptr);
    if (!p)
        return false;
    if (tail)
        tail -> next  = p;
    tail = p;
    if (!head)
        head = tail;
    ++cnt;
    return true;
}

bool List::DelFirst() {
    if (!head)
        return false;
    Node *p = head;
    head = head -> next;
    delete p;
    if (!head)
        tail = nullptr;
    --cnt;
    return true;
}

bool List::DelLast() {
    if (!tail)
        return false;
    Node *p = tail;
    tail = tail -> prev;
    delete p;
    if (!tail)
        head = nullptr;
    --cnt;
    return true;
}

Node* List::First() {
    return head;
}

Node* List::Last() {
    return tail;
}

int List::FirstZ() {
    return head -> inf;
}

int List::LastZ() {
    return tail -> inf;
}
bool List::Empty() {
    return cnt==0;
}

void List::Clear() {
    while (DelFirst());
}

int List::Size() {
    return cnt;
}

void List::Sort() {
    if (!head) return;
    bool flag = true;
    while (flag){
        flag = false;
        Node* p = head;
        while (p->next) {
            if (p->inf > p->next->inf) {
                int tmp = p->inf;
                p->inf = p->next->inf;
                p->next->inf = tmp;
                flag = true;
            }
            p = p->next;
        }
    }
}

void List::PrintHT() {
    Node *p = head;
    while (p) {
        cout << p->inf << " ";
        p = p -> next;
    }
    cout << endl;
}

void List::PrintTH() {
    Node *p = tail;
    while (p) {
        cout << p->inf << " ";
        p = p -> prev;
    }
    cout << endl;
}

int main()
{
    Node *n = new Node;
    n->inf = 5;

    cout << "Hello world!" << endl;
    delete n;

    List l;
    l.AddFirst(1);
    l.AddFirst(2);
    l.AddLast(3);
    l.AddLast(4);
    l.Sort();
    l.PrintHT();
    /*cout << l.First()->inf << endl;
    l.DelFirst();
    cout << l.FirstZ() << endl;
    l.DelFirst();
    cout << l.FirstZ() << endl;
    l.DelFirst();
    cout << l.FirstZ() << endl;
    l.DelFirst();*/
    return 0;
}
