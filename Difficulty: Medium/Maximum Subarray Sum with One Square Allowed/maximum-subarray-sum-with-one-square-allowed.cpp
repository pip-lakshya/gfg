class Solution {
public:
    int maximumSubarray(const vector<int>& arr) {
        if (arr.empty()) return 0;

        // Initialize state variables for the first element
        int dp0 = arr[0];
        int dp1 = arr[0] * arr[0];

        int max_sum = max(dp0, dp1);

        for (size_t i = 1; i < arr.size(); ++i) {
            int x = arr[i];
            int x_sq = x * x;

            // Calculate next states using the current dp0 and dp1
            int next_dp1 = max({x_sq, dp0 + x_sq, dp1 + x});
            int next_dp0 = max(x, dp0 + x);

            // Transition to the next element
            dp0 = next_dp0;
            dp1 = next_dp1;

            // Track the maximum sum found across all subarrays
            max_sum = max(max_sum, dp1);
        }

        return max_sum;
    }
};