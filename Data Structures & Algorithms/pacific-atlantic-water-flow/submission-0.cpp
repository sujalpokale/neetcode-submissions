class Solution {
public:
    int m ,n ;
    vector<vector<bool>> pacific,atlantic;

    void dfs(vector<vector<int>>& heights,int r, int c,vector<vector<bool>> & visited){
        visited[r][c] = true;

        int dr[4] = {-1,1,0,0};
        int dc[4] = {0,0,-1,1};

        for(int i=0;i<4;i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= m|| nc<0 || nc >= n){
                continue;
            }
            if(visited[nr][nc])
                continue;

            if(heights[nr][nc] >= heights[r][c]){
                dfs(heights,nr,nc,visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        pacific.assign(m,vector<bool>(n,false));
        atlantic.assign(m,vector<bool>(n,false));

        for(int j=0;j<n;j++){
            dfs(heights,0,j,pacific);
        }
        for(int i=0;i<m;i++){
            dfs(heights,i,0,pacific);
        }
        for(int j=0;j<n;j++){
            dfs(heights,m - 1,j,atlantic);
        }
        for(int i=0;i<m;i++){
            dfs(heights,i,n - 1,atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++){
            for(int j= 0;j<n;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
