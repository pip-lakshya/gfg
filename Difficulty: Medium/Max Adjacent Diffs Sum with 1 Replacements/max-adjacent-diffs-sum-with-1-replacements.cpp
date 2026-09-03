class Solution {
public:
    int maxDiffSum(vector<int>& arr) {
        int n = arr.size();

        if(n == 1)
            return 0;

        long long dp0 = 0; // current = arr[i]
        long long dp1 = 0; // current = 1

        for(int i = 1; i < n; i++) {
            long long new0 = max(
                dp0 + abs(arr[i] - arr[i-1]),
                dp1 + abs(arr[i] - 1)
            );

            long long new1 = max(
                dp0 + abs(1 - arr[i-1]),
                dp1 + abs(1 - 1)
            );

            dp0 = new0;
            dp1 = new1;
        }

        return max(dp0, dp1);
    }
};