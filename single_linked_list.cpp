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
    Node* head;
    Node* tail;
    Node* cursor;
    int size;

    public: 
        List():head(nullptr), tail(nullptr), cursor(nullptr), size(0){} // default constructor, no arguments
        ~List();
        void push_front(int data);
        void print();
        int  len() { return size; }
};

List::~List()
{    
    cout << "Calling List destructor.." << endl;
    /*
    for(cursor = head; cursor != nullptr; cursor = head->next)
    {
        cout << cursor << endl;
        //delete cursor;
    }
    */
    
}

void List::push_front(int data = 0)
{ 
    Node* new_node = new Node(data, head);  //point new node to current head 
    if(head == nullptr)
        tail = new_node;   //firts element point tail to node adress
    head = new_node;       //point head to new node
    size++;
} 

void List::print()
{
    cout << "HEAD:";
    for(Node* c = head; c != nullptr; c = c->next)
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

void splitList(node* start, node** ll1, node** ll2) 
{
   //similar to flyod's tortoise algorithm
   node* slow = start;
   node* fast = start -> next;

   while(fast != nullptr) 
   {
      fast = fast -> next;
      if(fast != nullptr) 
      {
         slow = slow -> next;
         fast = fast -> next;
      }
   }

   *ll1 = start;
   *ll2 = slow -> next;
   //spliting
   slow -> next = nullptr;
}


int main()
{   
    List l;
    for(int i = 0; i <= 8; i++)
        l.push_front(i);
    l.print();
    cout << l.len() << endl;
    return 0;
}