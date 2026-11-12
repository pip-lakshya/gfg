class Solution {
  public:
    int minDiff(Node *root, int K) {
        int min_diff = INT_MAX;
        Node* curr = root;

        while (curr != NULL) {
            int diff = curr->data - K;
            if (diff < 0) {
                diff = -diff;
            }

            if (diff < min_diff) {
                min_diff = diff;
            }

            if (curr->data == K) {
                return 0;
            } else if (K < curr->data) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return min_diff;
    }
};
