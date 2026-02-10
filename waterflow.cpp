#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool markGrid(vector<vector<int>> &grid,vector<vector<int>>& heights, int l, int m, int mk){
    if(mk == 0 && (l == 0 || m == 0)){
        grid[l][m] = 2;
        return true;
    }
    if(mk == 1 && (l == grid.size()-1||m == grid[0].size()-1)){
        grid[l][m] = 2;
        return true;
    }
    if(grid[l][m] == 1)
        return false;
    if(grid[l][m] == 2)
        return true;
    bool path = false;
    grid[l][m] = -1;
    if(l+1<grid.size() && heights[l+1][m] <= heights[l][m] && !path && grid[l+1][m]!=-1)
        path = markGrid(grid,heights,l+1,m,mk);
    if(l-1>=0 && heights[l-1][m] <= heights[l][m] && !path && grid[l-1][m]!=-1)
        path = markGrid(grid,heights,l-1,m,mk);
    if(m+1<grid[0].size() && heights[l][m+1] <= heights[l][m] && !path && grid[l][m+1]!=-1)
        path = markGrid(grid,heights,l,m+1,mk);
    if(m-1>=0 && heights[l][m-1] <= heights[l][m] && !path && grid[l][m-1]!=-1)
        path = markGrid(grid,heights,l,m-1,mk);
    if(path)
        grid[l][m] = 2;
    else
        grid[l][m] = 1;
    return path;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> pacific(m,vector<int>(n,0));
    vector<vector<int>> atlantic(m,vector<int>(n,0));
    vector<vector<int>> res;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pacific[i][j] == 0)
                markGrid(pacific,heights,i,j,0);
            if(atlantic[i][j] == 0)
                markGrid(atlantic,heights,i,j,1);
            if(atlantic[i][j] == 2 && pacific[i][j] == 2)
                res.push_back({i,j});
            cout << pacific[i][j] << "*" << atlantic[i][j] << " ";
        }
        cout << endl;
    }
    return res;
}

int main(){
    vector<vector<int>> ht = {{4,2,7,3,4},{7,4,6,4,7},{6,3,5,3,6}};
    pacificAtlantic(ht);
}