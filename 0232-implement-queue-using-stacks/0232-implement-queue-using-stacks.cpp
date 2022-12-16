class MyQueue {
public:   
    stack<int> input;
    stack<int> output;
    
    void push(int x) 
    {
        input.push(x);
    }
    
    int pop() 
    {
        if(!output.empty())
        {
            int val=output.top(); 
            output.pop();
            return val;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            int val=output.top(); 
            output.pop();
            return val;
        }
        
    }
    
    int peek() 
    {
        if(!output.empty())
            return output.top();
        
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    bool empty() 
    {
        if(output.empty() && input.empty())
            return true;
        else
            return false;
    }
};
