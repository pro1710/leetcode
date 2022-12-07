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
        if (!root) {
            return root;
        }

        queue<Node*> q;
        q.push(root);
        int currLayer = 1;
        int nextLayer = 0;

        while (!q.empty()) {
            Node* node = q.front();
            
            q.pop();
            currLayer--;

            if (node->left) {
                q.push(node->left);
                nextLayer++;
            }

            if (node->right) {
                q.push(node->right);
                nextLayer++;
            }  

            if (currLayer == 0) {
                node->next = nullptr;
                currLayer = q.size();
            } else {
                node->next = q.front();
            }
        }
        return root;
    }

    
};
