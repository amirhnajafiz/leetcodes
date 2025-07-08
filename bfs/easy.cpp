#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Simple BFS traversal for an unweighted graph
void bfs(int start, const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph: 0-1-2, 0-3
    vector<vector<int>> adj = {
        {1, 3},    // neighbors of node 0
        {0, 2},    // neighbors of node 1
        {1},       // neighbors of node 2
        {0}        // neighbors of node 3
    };

    cout << "BFS traversal starting from node 0: ";
    bfs(0, adj);
    cout << endl;

    return 0;
}
