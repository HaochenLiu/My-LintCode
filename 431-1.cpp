/*
431. Find the Connected Component in the Undirected Graph

Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)
Have you met this question in a real interview?
Example
Given graph:
A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E


Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
*/

/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int>> res;
        vector<int> record;
        int n = nodes.size();
        if(n == 0) return res;
        unordered_set<UndirectedGraphNode*> s;
        for(int i = 0; i < n; i++) {
            if(s.find(nodes[i]) != s.end()) continue;
            record.clear();
            queue<UndirectedGraphNode*> q;
            q.push(nodes[i]);
            s.insert(nodes[i]);
            record.push_back(nodes[i]->label);
            while(!q.empty()) {
                UndirectedGraphNode* node = q.front();
                q.pop();
                int m = node->neighbors.size();
                for(int j = 0; j < m; j++) {
                    if(s.find(node->neighbors[j]) == s.end()) {
                        q.push(node->neighbors[j]);
                        s.insert(node->neighbors[j]);
                        record.push_back(node->neighbors[j]->label);
                    }
                }
            }
            sort(record.begin(), record.end());
            res.push_back(record);
        }

        return res;
    }
};
