/*
178. Graph Valid Tree

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
Have you met this question in a real interview?
Example

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
Note

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/

class Solution {
public:
    /**
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        // Write your code here
        if(n == 0) return true;
        int e = edges.size();
        if(e != n - 1) return false;
        vector<int> degree(n, 0);
        for(int i = 0; i < e; i++) {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(degree[i] < 2) {
                q.push(i);
                res.push_back(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int i = 0; i < e; i++) {
                if(edges[i][0] == node || edges[i][1] == node) {
                    degree[edges[i][0]]--;
                    degree[edges[i][1]]--;
                    if(degree[edges[i][0]] == 1) {
                        q.push(edges[i][0]);
                        res.push_back(edges[i][0]);
                    }
                    if(degree[edges[i][1]] == 1) {
                        q.push(edges[i][1]);
                        res.push_back(edges[i][1]);
                    }
                }
            }
        }
        
        return (res.size() == n);
    }
};
