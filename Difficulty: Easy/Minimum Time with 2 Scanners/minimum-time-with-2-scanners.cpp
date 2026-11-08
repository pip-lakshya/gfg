class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        int low = 0;
        int high = n * (s1 < s2 ? s1 : s2);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Calculate how many documents each scanner can process within 'mid' time
            long long docs_by_s1 = mid / s1;
            long long docs_by_s2 = mid / s2;

            // If together they can process at least n documents, it's a valid time
            if (docs_by_s1 + docs_by_s2 >= n) {
                ans = mid;
                high = mid - 1; // Try to find a smaller valid time
            } else {
                low = mid + 1;  // Not enough time, increase it
            }
        }
        return ans;
    }
};
