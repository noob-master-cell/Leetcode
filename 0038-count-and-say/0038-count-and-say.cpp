class Solution {
public:
    string countAndSay(int n) 
    {
        vector<string> s;
        
        s.push_back("0");
        s.push_back("1");
        s.push_back("11");
        
        for(int i = 3; i <= n; i++)
        {
            string str = s[i-1];
            int len = str.size();
            string ans;
            
            for(int j = 0; j < len; j++)
            {
                int count=1;
                while(j < len-1 && str[j] == str[j+1])
                {
                    count++;
                    j++;
                }
                ans += count + '0';
                ans += str[j];
            }
            s.push_back(ans);
        }
        return s[n];
    }
};