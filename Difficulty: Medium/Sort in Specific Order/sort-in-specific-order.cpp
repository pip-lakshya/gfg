#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    void sortIt(vector<int>& arr) {
        // Move all odd numbers to the front and get the iterator where even numbers start
        auto mid = partition(arr.begin(), arr.end(), [](int x) {
            return x % 2 != 0;
        });

        // Sort the odd portion in descending order
        sort(arr.begin(), mid, greater<int>());

        // Sort the even portion in ascending order
        sort(mid, arr.end());
    }
};
