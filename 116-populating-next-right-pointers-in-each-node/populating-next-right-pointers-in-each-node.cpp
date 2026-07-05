/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)
            return root;

        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                Node* curr_ele = q.front().first;
                int level = q.front().second;
                q.pop();

                if (!q.empty() && level == q.front().second)
                    curr_ele->next = q.front().first;
                else if (q.empty())
                    curr_ele->next = NULL;

                if (curr_ele->left)
                    q.push({curr_ele->left, level + 1});

                if (curr_ele->right)
                    q.push({curr_ele->right, level + 1});
            }
        }

        return root;
    }
};