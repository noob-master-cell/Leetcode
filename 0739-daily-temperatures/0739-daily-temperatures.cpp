class Solution {
public:
    
    // Simple next greater element approach
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {        
        //stack for storing the index of next greater element
        stack<int> st;
        vector<int> ans(temperatures.size());
        
        // traversing from last 
        for(int i = temperatures.size()-1; i >= 0; i--)
        {
            if(st.empty())
                ans[i]=0;
            
            else
            {
                while(!st.empty())
                {
                    if(temperatures[st.top()] > temperatures[i])
                    {
                        ans[i]=st.top()-i;
                        break;
                    }
                    else
                        st.pop();
                
                }
                if(st.empty())
                    ans[i]=0;
           
            }
             st.push(i);
        }
        return ans;
        
    }
};