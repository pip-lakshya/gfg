class Solution {
public:
    int dominantPairs(vector<int> &arr) {

        int n = arr.size();
        int half = n / 2;

        vector<int> first(arr.begin(), arr.begin() + half);
        vector<int> second(arr.begin() + half, arr.end());

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        long long ans = 0;

        for (int x : first) {

            // Need: x >= 5 * second[j]
            // So: second[j] <= x / 5

            int low = 0, high = half;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if ((long long)second[mid] * 5 <= x)
                    low = mid + 1;
                else
                    high = mid;
            }

            ans += low;
        }

        return (int)ans;
    }
};