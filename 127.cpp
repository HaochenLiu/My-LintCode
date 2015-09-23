/*
127. Topological Sorting

Given an directed graph, a topological order of the graph nodes is defined as follow:
For each directed edge A -> B in graph, A must before B in the order list.
The first node in the order can be any node in the graph with no nodes direct to it.
Find any topological order for the given graph.
Have you met this question in a real interview?
Example
For graph as follow:

The topological order can be:
[0, 1, 2, 3, 4, 5]
[0, 2, 3, 1, 5, 4]
...


Note
You can assume that there is at least one topological order in the graph.
Challenge
Can you do it in both BFS and DFS?
*/

/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        unordered_map<DirectedGraphNode*, int> m;
        queue<DirectedGraphNode*> q;
        for(int i = 0; i < graph.size(); i++) {
            for(int j = 0; j < graph[i]->neighbors.size(); j++) {
                m[graph[i]->neighbors[j]]++;
            }
        }
        
        for(int i = 0; i < graph.size(); i++) {
            if(m[graph[i]] == 0) {
                q.push(graph[i]);
            }
        }
        
        while(!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            res.push_back(node);
            for(int i = 0; i < node->neighbors.size(); i++) {
                m[node->neighbors[i]]--;
                if(m[node->neighbors[i]] == 0) {
                    q.push(node->neighbors[i]);
                }
            }
        }
        
        return res;
    }
};
