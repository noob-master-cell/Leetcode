class Solution {
public:
    string breakPalindrome(string palindrome) 
    {
        int n = palindrome.length();
        if(n == 0 || n == 1)    
            return "";

        int i = 0;
        int j = n - 1;
        while(i < j) 
        {
            if(palindrome[i] == palindrome[j] && palindrome[i] != 'a')
            {
                palindrome[i] = 'a';
                return palindrome;
            }
            i++;
            j--;
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};