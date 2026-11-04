class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        int n = arr.size();

        // If array size is even, every element appears an even number of times
        if (n % 2 == 0) {
            return 0;
        }

        // If odd, XOR elements at even indices (0, 2, 4, ...)
        int res = 0;
        for (int i = 0; i < n; i += 2) {
            res ^= arr[i];
        }

        return res;
    }
};
