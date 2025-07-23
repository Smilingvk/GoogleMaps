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

class Queue {

    private:
        Node *Front, *rear;

    public:
        Queue(): Front(nullptr), rear(nullptr){};

        bool isEmpty(){
            return Front == nullptr;
        }

        void enqueue(int value){
            Node *newNode = new Node(value);
            if (isEmpty()) Front = rear = newNode;
            else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        void dequeue(){
            if (isEmpty()) return;
            Node *temp = Front;
            Front = Front -> next;
            delete temp;
            if (Front == nullptr) rear = nullptr;
        }
        
        int front(){
            if(isEmpty()) return -1;
            return Front -> data;
        }

        ~Queue() {
            while (!isEmpty()) dequeue();
        }
}