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
private:
    int getFather(unordered_map<int, int>& father, int i) {
        if(father.find(i) == father.end()) {
            father[i] = i;
            return i;
        }
        while(father[i] != i) {
            i = father[i];
        }
        return i;
    }

public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        // Write your code here
        vector<vector<int>> res;
        vector<int> record;
        int n = nodes.size();
        if(n == 0) return res;
        unordered_map<int, int> father;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < nodes[i]->neighbors.size(); j++) {
                int fa = getFather(father, nodes[i]->label);
                int fb = getFather(father, nodes[i]->neighbors[j]->label);
                father[fa] = min(fa, fb);
                father[fb] = min(fa, fb);
            }
        }
     
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            if(s.find(nodes[i]->label) != s.end()) continue;
            record.clear();
            s.insert(nodes[i]->label);
            record.push_back(nodes[i]->label);
            for(int j = i + 1; j < n; j++) {
                if(getFather(father, nodes[i]->label) == getFather(father, nodes[j]->label)) {
                    s.insert(nodes[j]->label);
                    record.push_back(nodes[j]->label);
                }
            }
            sort(record.begin(), record.end());
            res.push_back(record);
        }

        return res;
    }
};
