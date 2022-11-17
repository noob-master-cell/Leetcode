class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) 
    {
        int ra = (ax2 - ax1) * (ay2 - ay1);
        int rb = (bx2 - bx1) * (by2 - by1);
        int overlap = min(ax2, bx2) - max(ax1, bx1);
        if (overlap <= 0) 
            overlap = 0;
        else 
        {
            overlap *= min(ay2, by2) - max(ay1, by1);
            overlap = max(overlap, 0);
        }
        return ra + rb - overlap;
    }
};