/**
 * https://leetcode.com/problems/clone-graph/
 * By Nroskill
 * runtime 36 ms
 * language cpp
 */

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hash;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return NULL;
        if(hash.find(node) == hash.end()) {
            hash[node] = new UndirectedGraphNode(node->label);
            for(auto i : node->neighbors)
                hash[node]->neighbors.push_back(cloneGraph(i));
        }
        return hash[node];
    }
};