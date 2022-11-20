class Solution {
public:
    int calculate(string s) {
        int sign = 1;
        int ans = 0;
        int num = 0;
        int n = s.size();
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            char c = s[i];
            if(c >= '0' && c <= '9')
                num = num*10 + (c-'0');
            
            if(c == '-')
            {
                ans += sign * num;
                num = 0;
                sign = -1;
            }
            if(c == '+')
            {
                ans += sign * num;
                num = 0;
                sign = 1;
            }
            if(c == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
            }
            if(c == ')')
            {
                ans += sign * num;
                num = 0;
                ans = ans * st.top();
                st.pop();
                ans += st.top();
                st.pop();
            }
        }
        ans += sign * num;
        return ans;
    }
};