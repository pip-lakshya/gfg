class Solution {
public:

    int solve(Node* root, int mx) {

        if (root == NULL)
            return INT_MIN;

        // Current node is a descendant of the ancestor represented by mx
        int ans = mx - root->data;

        // This node can become the ancestor for its children
        mx = max(mx, root->data);

        int left = solve(root->left, mx);
        int right = solve(root->right, mx);

        return max(ans, max(left, right));
    }

    int maxDiff(Node* root) {

        int ans = INT_MIN;

        // Root itself should NOT be considered.
        if (root->left != NULL)
            ans = max(ans, solve(root->left, root->data));

        if (root->right != NULL)
            ans = max(ans, solve(root->right, root->data));

        return ans;
    }
};