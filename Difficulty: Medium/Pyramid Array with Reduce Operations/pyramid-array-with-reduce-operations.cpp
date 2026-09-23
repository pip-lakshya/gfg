class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();

        // left[i] = maximum pyramid height possible ending at i
        vector<int> left(n);

        left[0] = min(1, arr[0]);

        for (int i = 1; i < n; i++) {
            left[i] = min(arr[i], left[i - 1] + 1);
        }

        // right[i] = maximum pyramid height possible starting at i
        vector<int> right(n);

        right[n - 1] = min(1, arr[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(arr[i], right[i + 1] + 1);
        }

        // Maximum possible height at each position
        int maxHeight = 0;

        for (int i = 0; i < n; i++) {
            maxHeight = max(maxHeight, min(left[i], right[i]));
        }

        // Minimum number of stones that need to remain
        long long keep = 0;

        for (int h = 1; h <= maxHeight; h++) {
            keep += 2LL * h - 1;
        }

        long long total = 0;

        for (int x : arr)
            total += x;

        return (int)(total - keep);
    }
};