class Solution {
public:
    string reverseWords(string s) 
    {
        stack<string> str;
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            int curr = i;
            while(s[curr] == ' ' && curr < len)
                curr++;
            int start = curr;
            while(s[curr] != ' ' && curr < len)
                curr++;
            string word = s.substr(start, (curr-start));
            if(!word.empty())
                str.push(word);
            i = curr;
        }
        string ans;
        while(!str.empty())
        {
            ans += str.top() + ' ';
            str.pop();
        }
        ans.pop_back();
        return ans;
    }
};