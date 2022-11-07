class Solution {
public:
    int maximum69Number (int n) 
    {
        string num = to_string(n);
        for(auto &c : num) 
        {
            if(c == '6') 
            {
                c = '9';
                break;
            }
        }
        return stoi(num);
    }
};