class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<bool>& visited){
        visited[node] = true;

        for(int nei : graph[node]){
            if(!visited[nei]){
                dfs(nei,graph,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);

        int components = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                components++;
            }
        }
        return components;
    }
};

// class Solution {
// public:
//     int countComponents(int n, vector<vector<int>>& edges) {

//         vector<vector<int>> graph(n);

//         for (auto &e : edges) {
//             graph[e[0]].push_back(e[1]);
//             graph[e[1]].push_back(e[0]);
//         }

//         vector<bool> visited(n, false);
//         queue<int> q;

//         int components = 0;

//         for (int i = 0; i < n; i++) {

//             if (visited[i]) continue;

//             components++;

//             q.push(i);
//             visited[i] = true;

//             while (!q.empty()) {

//                 int node = q.front();
//                 q.pop();

//                 for (int nei : graph[node]) {

//                     if (!visited[nei]) {
//                         visited[nei] = true;
//                         q.push(nei);
//                     }
//                 }
//             }
//         }

//         return components;
//     }
// };
