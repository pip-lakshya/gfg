class Solution {
public:
    int maxPackages(vector<int>& arr, int totalTime) {
        int n = arr.size();

        if (totalTime <= 0 || n == 0)
            return 0;

        int k = min(totalTime, n);
        int sum = 0, ans = 0;

        for (int i = 0; i < k; i++) {
            sum += arr[i];
        }

        ans = sum;

        for (int i = k; i < n; i++) {
            sum += arr[i];
            sum -= arr[i - k];

            ans = max(ans, sum);
        }

        return ans;
    }
};