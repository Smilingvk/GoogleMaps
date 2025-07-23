struct Node {
    int data;
    Node *next;
    Node(int value) : data(value), next(nullptr){};
};

class Stack {
    public: 
    Node *top = nullptr;

    bool isEmpty(){return top == nullptr;}
    void push(int value){
        Node *newNode = new Node(value);
        top = newNode;
    }
    void pop() {
        if (isEmpty) return;
        Node *temp = top;
        top = top -> next;
        delete temp;
    }
    ~Stack(){while (!isEmpty()) pop();}
};