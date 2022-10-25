class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s1 = accumulate(word1.begin(), word1.end(), string(""));
        string s2 = accumulate(word2.begin(), word2.end(), string(""));
        if(s1.length() != s2.length())
            return false;
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i]!=s2[i])
                return  false;
        }
        return true;
    }
};