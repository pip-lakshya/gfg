class Solution {
public:
    int minMoves(vector<int>& arr) {
        int n = arr.size();

        vector<int> pos(n + 1);

        // Store position of every number
        for(int i = 0; i < n; i++) {
            pos[arr[i]] = i;
        }

        int longest = 1;
        int curr = 1;

        for(int i = 1; i < n; i++) {

            if(pos[i] < pos[i + 1]) {
                curr++;
            }
            else {
                curr = 1;
            }

            longest = max(longest, curr);
        }

        return n - longest;
    }
};