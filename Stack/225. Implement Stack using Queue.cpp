class Node
{
    public:

    int data;
    Node* next;

    Node() {
    }

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    public: 

    int size;
    Node* front;
    Node* back;

    Queue()
    {
        size = 0;
        front = back = NULL;
    }

    bool empty()
    {
        return size == 0;
    }

    void enQueue(int val)
    {
        Node* newNode = new Node(val);
        size++;

        if(front == NULL && back == NULL)
        {
            front = back = newNode;
            return;
        }

        back->next = newNode;
        back = newNode;
    }

    int deQueue()
    {
        int val = front->data;
        size--;

        Node* aux = front;
        front = front->next;

        delete aux;

        if(front == NULL)
        {
            front = back = NULL;
        }

        return val;
    }

    int frontt()
    {
        return front->data;
    }

    int backk()
    {
        return back->data;
    }
};

class MyStack {
public:
    Queue q;

    MyStack() 
    {
    }
    
    void push(int x) 
    {
        
        q.enQueue(x);
        
        int val;
        int size = q.size;

        for(int i = 0; i < size-1; i++)
        {
            val = q.deQueue();
            q.enQueue(val);
        }
    }
    
    int pop() 
    {
        return q.deQueue();
    }
    
    int top() 
    {
        return q.frontt();
    }
    
    bool empty() 
    {
        return q.empty();    
    }
};
