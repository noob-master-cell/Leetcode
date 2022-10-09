class Solution
{
    public:
        double findMedianSortedArrays(vector<int> &n1, vector<int> &n2)
        {
            int n = n1.size();
            int m = n2.size();
            int i = n - 1;
            int j = m - 1;
            int k = m + n; //size of vector after merging
            
            n1.resize(k); // resize n1 vector for inplace merge
            k = k - 1;
            while (i >= 0 && j >= 0)
            {
                if (n1[i] > n2[j])
                {
                    n1[k] = n1[i];
                    k--;
                    i--;
                }
                else
                {
                    n1[k] = n2[j];
                    k--;
                    j--;
                }
            }
            while (j >= 0)
            {
                n1[k] = n2[j];
                k--;
                j--;
            }
            
            k = m + n;
            if (k % 2 == 1)
                i = j = (k) / 2;
            else
            {
                i = (k / 2) - 1;
                j = i + 1;
            }
            return (n1[i] + n1[j]) / 2.0;
        }
};