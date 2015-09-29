/*
176. Route Between Two Nodes in Graph

Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
Have you met this question in a real interview?
Example
Given graph:
A----->B----->C
 \     |
  \    |
   \   |
    \  v
     ->D----->E


for s = B and t = E, return true
for s = D and t = C, return false
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
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        // write your code here
        if(!s || !t) return false;
        if(s == t) return true;
        map<DirectedGraphNode*, bool> m;
        queue<DirectedGraphNode*> q;
        q.push(s);
        while(!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            m[node] = true;
            for(int i = 0; i < node->neighbors.size(); i++) {
                if(node->neighbors[i] == t) {
                    return true;
                } else if(m.find(node->neighbors[i]) == m.end()) {
                    m[node->neighbors[i]] = true;
                    q.push(node->neighbors[i]);
                }
            }
        }
        return false;
    }
};


