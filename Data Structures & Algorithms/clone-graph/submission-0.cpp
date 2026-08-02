/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    map<Node*, Node*> oldToNew;
    Node* cloneGraph(Node* node) { return deepCopy(node); }
    Node* deepCopy(Node* original) {
        if (original == nullptr) return nullptr;
        if (oldToNew.count(original)) return oldToNew[original];
        Node* copy = new Node(original->val);
        oldToNew[original] = copy;
        for (auto x : original->neighbors) {
            copy->neighbors.push_back(deepCopy(x));
        }
        return copy;
    }
};
