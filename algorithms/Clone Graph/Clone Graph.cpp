/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    UndirectedGraphNode * getNode(int label, unordered_map<int, UndirectedGraphNode *> &M) {
        if(M.find(label) == M.end()) {
            M[label] = new UndirectedGraphNode(label);
        }
        return M[label];
    }
    void dfs(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &M) {
        int now_label = node->label;
        UndirectedGraphNode *now_node = getNode(now_label, M);
        for(int i = 0; i < node->neighbors.size(); i++) {
            auto next_node = node->neighbors[i];
            bool flag = M.find(next_node->label) == M.end();
            auto next_node_ = getNode(next_node->label, M);
            now_node->neighbors.push_back(next_node_);
            if(flag) {
                dfs(next_node, M);
            }
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        unordered_map<int, UndirectedGraphNode *> M;
        UndirectedGraphNode *ret_node = getNode(node->label, M);
        dfs(node, M);
        return ret_node;
    }
};