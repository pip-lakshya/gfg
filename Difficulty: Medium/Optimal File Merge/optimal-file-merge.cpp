class Solution {
public:
    int minComputation(vector<int> &files) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : files)
            pq.push(x);

        int cost = 0;

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();

            int b = pq.top();
            pq.pop();

            int sum = a + b;
            cost += sum;
            pq.push(sum);
        }

        return cost;
    }
};