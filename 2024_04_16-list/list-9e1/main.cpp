#include <iostream>

using namespace std;

struct Node{
    int inf = 0;
    Node *prev = nullptr, *next = nullptr;
    Node();
    ~Node();
    Node(int n);
    Node(int n, Node *prev, Node *next);
};

Node::Node() {
    cout << "Create node with inf = " << inf << endl;
}

Node::~Node() {
    cout << "Delete node with inf = " << inf << endl;
}

Node::Node(int n) {
    inf = n;
    cout << "Create node with inf = " << inf << endl;
}

Node::Node(int n, Node *prevp, Node *nextp) {
    inf = n;
    prev = prevp;
    next = nextp;
    cout << "Create node with inf = " << inf << endl;
}

struct List{
    Node *head = nullptr, *tail = nullptr;
    int cnt = 0;

    void AddFirst(int n);
    void AddLast(int n);
    bool DelFirst();
    bool DelLast();
    int First();
    int Last();
    void Clear();
    void Sort();
    bool Empty();
    int Size();
    void PrintHT();
    void PrintTH();
    ~List();
};

void List::AddFirst(int n) {
    Node *p = new Node(n, nullptr, head);
    if (head)
        head->prev = p;
    head = p;
    if (!tail)
        tail = p;
    ++cnt;
}

void List::AddLast(int n) {
    Node *p = new Node(n, tail, nullptr);
    if (tail)
        tail->next = p;
    tail = p;
    if (!head)
        head = p;
    ++cnt;
}

bool List::DelFirst() {
    if (!head)
        return false;
    Node *p = head;
    head = head->next;
    delete p;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    --cnt;
    return true;
}

bool List::DelLast() {
    if (!tail)
        return false;
    Node *p = tail;
    tail = tail->prev;
    delete p;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    --cnt;
    return true;
}

int List::First() {
    return head->inf;
}

int List::Last() {
    return tail->inf;
}

void List::Clear() {
    while (DelFirst());
}

void List::Sort() {
    if (!head) return;

    bool flag = true;
    while (flag) {
        flag = false;
        Node *p = head;
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

bool List::Empty() {
    return cnt==0;
}

int List::Size() {
    return cnt;
}

List::~List() {
    Clear();
}

void List::PrintHT() {
    Node *p = head;
    while (p) {
        cout << p->inf << " ";
        p = p->next;
    }
    cout << endl;
}

void List::PrintTH() {
    Node *p = tail;
    while (p) {
        cout << p->inf << " ";
        p = p->prev;
    }
    cout << endl;
}

int main()
{
    Node p(5);
    p.inf = 41;

    cout << "Hello world!" << endl;

    List l;
    l.AddFirst(1);
    l.AddFirst(2);
    l.AddLast(3);
    l.AddLast(4);
    l.PrintHT();
    l.PrintTH();
    l.Sort();
    l.PrintHT();
    l.PrintTH();

    return 0;
}
