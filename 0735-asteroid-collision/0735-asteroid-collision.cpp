class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) 
    {
        stack<int> stk; //Stack to store asteroids after collision resolution
        
        for(int i=0; i<ast.size(); i++)
        {
            if(stk.empty()){
                stk.push(ast[i]); // If the stack is empty push the current asteroid 
            }
            else if(stk.top() > 0 && ast[i] < 0)
            { 
                // If the top asteroid in the stack is positive (moving right) and the current asteroid is negative (moving left) then check for collision
            
                if(stk.top() > abs(ast[i]))
                {
                    // If the top asteroid's size is greater than the current asteroid's size in absolute value, no collision occurs then skip the current asteroid
                    continue;
                }
                
                // If there is a collision and the current asteroid size is greater than the top asteroid size keep popping asteroids from the stack until there are no more collisions possible or the top asteroid is destroyed
                while(!stk.empty() && stk.top() > 0 && ast[i] < 0 && stk.top() < abs(ast[i]))
                {
                    stk.pop(); 
                } 
                
                if(!stk.empty() && stk.top() > 0 && ast[i] < 0 && stk.top() == abs(ast[i]))
                {
                    // If there is a collision and the current asteroid size is equal to the top asteroid size then both asteroids are destroyed so pop the top asteroid from the stack
                    stk.pop();
                    continue;  
                }
                
                if(!stk.empty() && stk.top() > abs(ast[i]))
                {
                    // If there is a collision and the top asteroid size is greater than the current asteroid size then no collision occurs so skip the current asteroid
                    continue; 
                } 
                stk.push(ast[i]);
            }
            else if(stk.top() < 0 && ast[i] > 0)
            {
                // If the top asteroid is negative (moving left) and the current asteroid is positive (moving right) then no collision occurs push the current asteroid 
                stk.push(ast[i]);
            }
            else if((stk.top() > 0 && ast[i] > 0) || (stk.top() < 0 && ast[i] < 0))
            {
                // If both the top asteroid and the current asteroid have the same direction (both positive or both negative) then no collision occurs push the current asteroid
                stk.push(ast[i]);
            } 
        }
        vector<int> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};