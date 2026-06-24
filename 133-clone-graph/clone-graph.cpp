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
    void dfs(Node* node, unordered_map<Node*, Node*> &visited){
        visited[node] = new Node(node->val);
        for(Node* x : node->neighbors){
            if (visited.find(x) == visited.end()) {
                dfs(x, visited);
            }
            visited[node]->neighbors.push_back(visited[x]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr;
        }
        unordered_map<Node*, Node*> visited;
        dfs(node, visited);
        return visited[node];
    }
};