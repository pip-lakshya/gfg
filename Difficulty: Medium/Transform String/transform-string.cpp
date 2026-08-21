class Solution {
public:
    int transform(string s1, string s2) {

        if(s1.size() != s2.size())
            return -1;

        // Check whether both strings contain same characters
        unordered_map<char, int> mp;

        for(char c : s1)
            mp[c]++;

        for(char c : s2)
            mp[c]--;

        for(auto p : mp) {
            if(p.second != 0)
                return -1;
        }

        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int ans = 0;

        // Match from the end
        while(i >= 0) {

            if(s1[i] == s2[j]) {
                j--;
            }
            else {
                ans++;
            }

            i--;
        }

        return ans;
    }
};