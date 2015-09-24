/*
432. Find the Weak Connected Component in the Directed Graph

Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors. (a connected set of a directed graph is a subgraph in which any two vertices are connected by direct edge path.)
Have you met this question in a real interview?
Example
Given graph:
A----->B  C
 \     |  | 
  \    |  |
   \   |  |
    \  v  v
     ->D  E <- F


Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}
Note
Sort the element in the set in increasing order
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
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    int find(unordered_map<int, int> &father, int x) {
        if (father.find(x) == father.end()) {
            father[x] = x;
            return x;
        }
        while (x != father[x]) {
            x = father[x];
        }
        return x;
    }
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        unordered_map<int, int> father;
        int fa, fb, fn;
        for (auto &n : nodes) {
            for (auto &nn : n->neighbors) {
                fa = find(father, n->label);
                fb = find(father, nn->label);
                if (fa != fb) {
                    father[fa] = min(fa, fb);
                    father[fb] = min(fa, fb);
                }
            }
        }
        unordered_map<int, vector<int>> comp;
        for (auto &n : nodes) {
            fn = find(father, n->label);
            comp[fn].push_back(n->label);
        }
        vector<vector<int>> res;
        for (auto &c : comp) {
            sort(c.second.begin(), c.second.end());
            res.push_back(c.second);
        }
        return res;
    }
};
