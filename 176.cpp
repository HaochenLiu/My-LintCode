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

#include <unordered_set>
using namespace std;
/**
* Definition for Directed graph.
* struct DirectedGraphNode {
*     int label;
*     vector<DirectedGraphNode *> neighbors;
*     DirectedGraphNode(int x) : label(x) {};
* };
*/
typedef DirectedGraphNode DGN;

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DGN *> graph, DGN *s, DGN *t) {
        // The parameter "graph" is useless?
        if (s == NULL || t == NULL) {
            return false;
        }
        if (s == t) {
            return true;
        }
        us.clear();
        return reachable(s, t);
    }
private:
    unordered_set<DGN *> us;
   
    bool reachable(DGN *s, DGN *t) {
        if (s == t) {
            return true;
        }
        int n = s->neighbors.size();
        int i;
        us.insert(s);
        for (i = 0; i < n; ++i) {
            if (us.find(s->neighbors[i]) != us.end()) {
                continue;
            }
            if (reachable(s->neighbors[i], t)) {
                return true;
            }
        }
        return false;
    }
};
