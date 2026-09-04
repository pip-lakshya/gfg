class Solution {
public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        int sum = 0;

        // First window
        for(int i = 0; i < m; i++) {
            sum += arr[i];
        }

        int ans = sum;

        // Sliding over circular array
        for(int i = 1; i < n; i++) {
            sum -= arr[i - 1];
            sum += arr[(i + m - 1) % n];

            ans = max(ans, sum);
        }

        return ans;
    }
};