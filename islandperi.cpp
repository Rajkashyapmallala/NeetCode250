#include <bits/stdc++.h>
using namespace std;

    int res = 0;

    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int n){
        if(i<0||j<0||i>=n||j>=n||!grid[i][j]){
            res += 1;
            return;
        }
        if(vis[i][j])
            return;
        vis[i][j] = true;
        dfs(grid,i+1,j,vis,n);
        dfs(grid,i-1,j,vis,n);
        dfs(grid,i,j+1,vis,n);
        dfs(grid,i,j-1,vis,n);
    }

    static int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    dfs(grid,i,j,vis,n);
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        return res;
    }
int main() {
    vector<vector<int>> grid = {{1,0}};
    cout << islandPerimeter(grid);
    return 0;
}