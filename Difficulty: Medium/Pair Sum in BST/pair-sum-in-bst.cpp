/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:

    bool dfs(Node *root, unordered_set<int> &st, int target) {
        if (root == nullptr)
            return false;

        if (st.find(target - root->data) != st.end())
            return true;

        st.insert(root->data);

        return dfs(root->left, st, target) || dfs(root->right, st, target);
    }

    bool findTarget(Node *root, int target) {
        unordered_set<int> st;
        return dfs(root, st, target);
    }
};