class Solution {
public:

    // Count triplets having sum <= x
    long long countLessEqual(vector<int>& arr, int x) {

        int n = arr.size();
        long long count = 0;

        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)arr[i]
                              + arr[left]
                              + arr[right];

                if (sum <= x) {

                    // If i + left + right <= x,
                    // then all elements from left to right
                    // will also satisfy it.
                    count += (right - left);

                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return count;
    }

    int countTriplets(vector<int>& arr, int l, int r) {

        sort(arr.begin(), arr.end());

        // Number of triplets with sum <= r
        long long rightCount = countLessEqual(arr, r);

        // Number of triplets with sum < l
        long long leftCount = countLessEqual(arr, l - 1);

        return rightCount - leftCount;
    }
};