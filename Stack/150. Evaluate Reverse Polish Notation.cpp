int evalRPN(vector<string>& tokens) {
  
        stack<int> stack;

        string aux = "";
        int size = tokens.size();
        int a, b, c;

        for(int i = 0; i < size; i++)
        {
            aux = tokens[i];

            if(aux == "+")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                c = a + b;
                stack.push(c);
            }
            else if(aux == "-")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                c = b - a;
                stack.push(c);
            }
            else if(aux == "*")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                c = a * b;
                stack.push(c);
            }
            else if(aux == "/")
            {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                c = b / a;
                stack.push(c);
            }
            else
            {
                stack.push(stoi(aux));
            }

        }

        return stack.top();
    }
