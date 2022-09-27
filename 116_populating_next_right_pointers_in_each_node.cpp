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
        
        if (root) {
            queue<Node*> nodes;
            nodes.push(root);
            
            while (!nodes.empty()) {
                    
                for (int i = 0, n = nodes.size(); i < n; ++i) {
                    
                    Node* first = nodes.front();
                    nodes.pop();
                    
                    if (first->left && first->right) {
                        nodes.push(first->left);
                        nodes.push(first->right);
                    }
                    
                    if (i != n-1) {
                        first->next = nodes.front();
                    }
                }
            } 
        }
        return root;
    }
  
};
