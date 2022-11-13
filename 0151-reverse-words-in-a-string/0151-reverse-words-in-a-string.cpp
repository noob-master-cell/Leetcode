class Solution {
public:

    string reverseWords(string s) 
    {
        int len = s.length();
        stack<string>st;

        for(int i=0;i<len;i++)
        {
            int curr = i;

            while(s[curr] == ' '  && curr<len)
                curr++;
            
            int start = curr;
            
            while(s[curr] != ' ' && curr<len)
                curr++;
        
            string word = s.substr(start, (curr-start));
            
            if(!word.empty())
               st.push(word);
            
            i = curr;
        }
    
        string ans = "";
        while(!st.empty()){
            ans += st.top() +" ";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};