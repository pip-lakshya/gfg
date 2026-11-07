class Solution {
  public:
    vector<string> generateUsernames(vector<string> arr) {
        // Track all initially reserved names from the input
        unordered_set<string> reserved(arr.begin(), arr.end());

        // Track names that have already been assigned
        unordered_set<string> used;

        // Optimisation: Track the next suffix integer to try for each base name
        unordered_map<string, int> count_map;

        vector<string> result;
        result.reserve(arr.size());

        for (const string& name : arr) {
            // Case 1: Name hasn't been assigned to anyone yet
            if (used.find(name) == used.end()) {
                result.push_back(name);
                used.insert(name);
            } 
            // Case 2: Name is already taken, look for the smallest available suffix
            else {
                int suffix = count_map.count(name) ? count_map[name] : 1;

                while (true) {
                    string candidate = name + to_string(suffix);

                    // Valid if it is not in the original input array AND not yet assigned
                    if (reserved.find(candidate) == reserved.end() && used.find(candidate) == used.end()) {
                        result.push_back(candidate);
                        used.insert(candidate);

                        // Save the next number to try for future encounters of this name
                        count_map[name] = suffix + 1;
                        break;
                    }
                    suffix++;
                }
            }
        }

        return result;
    }
};
