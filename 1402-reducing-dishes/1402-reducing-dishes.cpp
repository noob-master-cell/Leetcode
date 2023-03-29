class Solution {
public:


int maxSatisfaction(vector<int>& satisfaction) {
    int n = satisfaction.size();
    
    // Sort the satisfaction array in ascending order
    sort(satisfaction.begin(), satisfaction.end());
    
    // Calculate the maximum sum of like-time coefficients
    int max_sum = 0, curr_sum = 0, total_time = 0;
    for (int i = n - 1; i >= 0; --i) {
        total_time += satisfaction[i];
        curr_sum += total_time;
        max_sum = max(max_sum, curr_sum);
    }
    
    return max_sum;
}
};