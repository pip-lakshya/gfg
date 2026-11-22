class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> firstIdx; // remainder -> earliest index
        firstIdx[0] = -1;                 // empty prefix has remainder 0
        int pref = 0, max_len = 0;
        for (int j = 0; j < n; j++) {
            pref += arr[j];
            int r = ((pref % k) + k) % k; // normalize negative remainders
            if (firstIdx.count(r))
                max_len = max(max_len, j - firstIdx[r]);
            else
                firstIdx[r] = j;          // store ONLY the first occurrence
        }
        return max_len;
    }
};