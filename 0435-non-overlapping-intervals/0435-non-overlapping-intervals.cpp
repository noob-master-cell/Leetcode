class Solution {
public:
    //function to compare two intervals based on their ending points (v1[1] and v2[1])
    static bool compare(vector<int>& v1, vector<int>& v2) {
        return v1[1] < v2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        // Sort the intervals based on their ending points in ascending order
        sort(intervals.begin(), intervals.end(), compare);
        
        int prev = 0; // Index of the last interval with the smallest ending point
        int res = 0;  // to store the count of overlapping intervals

        for (int i = 1; i < intervals.size(); i++) 
        {
            // If the ending point of the previous interval is greater than the starting point of the current interval
            // it means there is an overlap and we need to remove one of the intervals
            if (intervals[prev][1] > intervals[i][0])
                res++;
            else 
            {
                // If there is no overlap update the "prev" index to the current interval for the next iteration
                prev = i;
            }
        }
        return res;
    }
};