#include<iostream>
using namespace std;
void dfs(int node, vector<bool>& visited, vector<vector<int>>& graph) {
    visited[node] = true;//visiting a new node
    cout << node << " ";

    for(int i = 0;i<graph[node].size();i++) {
        int neighbor = graph[node][i];
        if(!visited[neighbor]) {
            dfs(neighbor, visited, graph);
        }
    }
}
int main(){
    vector<vector<int>> graph(6);
    graph[1].push_back(2);

    graph[2].push_back(1);
    graph[2].push_back(3);

    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[3].push_back(5);

    graph[4].push_back(3);

    graph[5].push_back(3);

    vector<bool> visited(6, false);
    cout << "DFS starting from node 1: ";
    dfs(1, visited, graph);
    cout << endl;
    visited.assign(6, false); // Reset visited for another DFS
    cout<< "DFS starting from node 2: ";
    dfs(2, visited, graph);
    cout << endl;
    visited.assign(6, false); // Reset visited for another DFS
    cout<< "DFS starting from node 3: ";
    dfs(3, visited, graph);
    cout << endl;
    visited.assign(6, false); // Reset visited for another DFS
    cout<< "DFS starting from node 4: ";
    dfs(4, visited, graph);
    cout << endl;
    queue<int> q;
    vector<bool> visitedBFS(6, false);
    q.push(3);
    cout<< "BFS starting from node 3: ";
    visitedBFS[3] = true;
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for(int i = 0; i < graph[current].size(); i++) {
            int neighbor = graph[current][i];
            if(!visitedBFS[neighbor]) {
                visitedBFS[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}