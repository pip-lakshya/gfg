class Solution {
  public:
   char posInfinite(string& s, int pos) {
    int n = s.size();
    vector<int> len;
    len.push_back(n);

    while (len.back() < pos) {
        int step = len.size();
        int prev = len.back();
        len.push_back(2 * prev + step);
    }

    int idx = pos;
    for (int step = static_cast<int>(len.size()) - 1; step >= 1; --step) {
        int prev = len[step - 1];
        if (idx <= prev) {
            continue;
        } else if (idx <= prev + step) {
            return '$';
        } else {
            int offset = idx - (prev + step);
            idx = prev - offset + 1;
        }
    }

    return s[idx - 1];
}};