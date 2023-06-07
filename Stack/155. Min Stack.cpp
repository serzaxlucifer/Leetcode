class MinStack {
public:

    stack<int> mainStack;
    stack<int> minStack;

    // Employ Two Stacks. Can also use data format pair<int, int> representing <coming value, minimum value till here> format to store data in the stack but that stores the same data repetitely although it may have its own time benefits. Idk.

    MinStack() 
    {
    }
    
    void push(int val) 
    {
        mainStack.push(val);

        if(minStack.empty() || minStack.top() >= val)
        {
            minStack.push(val);
        }
    }
    
    void pop() 
    {
        int popped = mainStack.top();
        mainStack.pop();

        if(minStack.top() == popped)
        {
            minStack.pop();
        }
    }
    
    int top() 
    {
        return mainStack.top();
    }
    
    int getMin() 
    {
        return minStack.top();
    }
};

// using a special data format/structure. Without using inbuilt stacks.

// use an array!

class MinStack {
public:

    vector<pair<int, int>> stack;

    MinStack() 
    {
    }
    
    void push(int val) 
    {
        if(stack.empty())
        {
            stack.push_back({val,val});
        }
        else
        {
            stack.push_back({val, min(stack.back().second, val)});
        }
    }
    
    void pop() 
    {
        stack.pop_back();
    }
    
    int top() 
    {
        return stack.back().first;
    }
    
    int getMin() 
    {
        return stack.back().second;
    }
};

