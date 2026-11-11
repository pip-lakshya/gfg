class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        unordered_map<int, int> last;
        for (int i = 0; i < (int)arr.size(); i++) {
            if (last.count(arr[i]) && i - last[arr[i]] <= k) return true;
            last[arr[i]] = i;
        }
        return false;
    }
};