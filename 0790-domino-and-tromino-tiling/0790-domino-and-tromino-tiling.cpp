class Solution {
public:
    int numTilings(int n) 
    {
        int first  = 0;
        int second = 1;
        int third = 1;
        int mod = 1e9+7 ;
        int next;
        
        while(--n)
        {
            next = ((third * 2) % mod + first) % mod;
            first = second ;
            second = third ;
            third = next ;
        }
        return third ;
    }
};