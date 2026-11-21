class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr,int x) {
        int n = arr.size();
        int min_len = INT_MAX;
        int curr_sum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            curr_sum += arr[right];

            while (curr_sum > x) {
                min_len = min(min_len, right - left + 1);
                curr_sum -= arr[left];
                left++;
            }
        }

        return (min_len == INT_MAX) ? 0 : min_len;
    }
};
