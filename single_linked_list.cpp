#include<bits/stdc++.h>
using namespace std;

class Node 
//define node to store data and next address
{ 
    public:
        int data;
        Node* next;
        Node(int d = 0, Node* ptr = nullptr): data(d), next(ptr) {}
        ~Node() { cout << "Calling destructor for " << this << endl; }
};

class List
{

};

Node* push_front(int d) 
{
    Node* temp = new Node;

    temp -> data = d;
    temp -> next = nullptr;
    return temp;
}

void print(const Node* start)
{
    cout << "HEAD:";
    for(Node* c = const_cast<Node* const>(start); c != nullptr; c = c->next)
        cout << c << "(" << c->data << ")->";
    cout << "###" << endl;
}

Node* find(const Node* start, const int d)
{
    for(Node* c = const_cast<Node* const>(start); c != nullptr; c = c->next)
        if(c->data == d)
            return c;

    return nullptr;
}

int main()
{
    Node* c = push_front(9);    //buliding list, first node
    const Node* head = c;       //saving head of the list

    for(int i = 8; i >= 0; i--)
    {   
        Node* t = push_front(i); //temporaly node
        c->next = t;
        c = t;
    }

    print(head);

    cout << find(head, 4) << endl;

    return 0;
}