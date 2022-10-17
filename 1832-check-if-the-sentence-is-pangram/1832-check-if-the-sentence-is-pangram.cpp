class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        unordered_map<char, int> m;
        
        for(int i=0; i<sentence.size(); i++)
            m[sentence[i]]++;
        
        for(char ch='a'; ch<='z'; ch++)
        {
            if(m.find(ch)==m.end())
                return false; 
        }
        
        return true;
    }
};