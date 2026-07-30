class Solution {
public:
    vector<vector<int>> graph;
    vector<int> state;

    bool dfs(int node){
        state[node] = 1;

        for(int nei: graph[node]){
            if(state[nei] == 1)
                return false;

            if(state[nei] == 0){
                if(!dfs(nei))
                    return false;
            }
        }
        state[node] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        state.assign(numCourses,0);

        for(auto &p : prerequisites){
            graph[p[1]].push_back(p[0]);
        }

        for(int i=0;i < numCourses;i++){
            if(state[i] == 0){
                if(!dfs(i))
                    return false;
            }
        }
        return true;
    }
};
