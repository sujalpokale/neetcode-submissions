class Solution {
public:
    bool dfs(int node,int parent,vector<vector<int>>& graph,vector<bool>& visited){
        visited[node] = true;

        for(int nei : graph[node]){
            if(!visited[nei]){
                if(!dfs(nei,node,graph,visited)){
                    return false;
                }
            }
            else if(nei != parent){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1)
            return false;
        
        vector<vector<int>> graph(n);

        for(auto &e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n,false);

        if(!dfs(0,-1,graph,visited))
            return false;
        
        for(bool v : visited){
            if(!v)
                return false;
        }

        return true;
    }
};
