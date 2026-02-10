#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, int prev,vector<vector<bool>>& vis, vector<vector<int>>& memo){
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=prev || vis[i][j])
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        vis[i][j] = true;
        memo[i][j] = 1 + max({dfs(matrix,i+1,j,matrix[i][j],vis,memo),dfs(matrix,i-1,j,matrix[i][j],vis,memo),
        dfs(matrix,i,j+1,matrix[i][j],vis,memo),dfs(matrix,i,j-1,matrix[i][j],vis,memo)});
        vis[i][j] = false; 
        return memo[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 1;
        vector<vector<int>> memo(m,vector<int>(n,-1));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                res = max(res,dfs(matrix,i,j,INT_MIN,vis,memo));
            }
        }
        return res;   
    }
};

int main() {
    class Solution sol;
    vector<vector<int>> ma = {{5,5,3},{2,3,6},{1,1,1}};
    cout << sol.longestIncreasingPath(ma);
    return 0;
}