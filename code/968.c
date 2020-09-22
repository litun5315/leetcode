/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Status {
    int a, b, c;
};

struct Status dfs(struct TreeNode* root) {
    if (!root) {
        return (struct Status){INT_MAX / 2, 0, 0};
    }
    struct Status l = dfs(root->left);
    struct Status r = dfs(root->right);
    int a = l.c + r.c + 1;
    int b = fmin(a, fmin(l.a + r.b, r.a + l.b));
    int c = fmin(a, l.b + r.b);
    return (struct Status){a, b, c};
}

int minCameraCover(struct TreeNode* root) {
    struct Status ret = dfs(root);
    return ret.b;
}