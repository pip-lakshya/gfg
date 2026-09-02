class Solution {
public:
    int solve(int n, string s) {
        vector<int> state(26, 0);

        // 0 = customer abhi nahi aaya
        // 1 = customer computer use kar raha hai
        // 2 = customer reject ho gaya

        int occupied = 0;
        int ans = 0;

        for(char ch : s) {
            int x = ch - 'A';

            // First occurrence = arrival
            if(state[x] == 0) {
                if(occupied < n) {
                    state[x] = 1;
                    occupied++;
                }
                else {
                    state[x] = 2;
                    ans++;
                }
            }

            // Second occurrence = departure
            else if(state[x] == 1) {
                occupied--;
                state[x] = 0;
            }

            // state == 2 means customer was rejected
            else {
                state[x] = 0;
            }
        }

        return ans;
    }
};