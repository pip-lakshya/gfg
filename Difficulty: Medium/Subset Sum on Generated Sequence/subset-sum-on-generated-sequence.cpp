class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {

        vector<int> nums;

        long long sum = s;
        nums.push_back(s);

        for(int i = 0; i < arr.size(); i++) {

            long long next = sum + arr[i];

            sum += next;

            if(next > x)
                break;

            nums.push_back((int)next);
        }

        // Bitset DP
        bitset<100001> dp;
        dp[0] = 1;

        for(int val : nums) {
            dp |= (dp << val);
        }

        return dp[x];
    }
};