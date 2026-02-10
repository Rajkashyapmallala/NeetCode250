#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dfs(string s, string t, int i, int j, vector<vector<int>> memo){
        // cout << i << j << endl;
        if(j>=t.size())
            return 1;
        if(i>=s.size())
            return 0;
        if(memo[i][j]!=-1)
            return memo[i][j];
        memo[i][j] = dfs(s,t,i+1,j,memo);
        if(s[i] == t[j]){
            memo[i][j] += dfs(s,t,i+1,j+1,memo);
        }
        return memo[i][j];
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(n>m)
            return 0;
        vector<vector<int>> memo(m,vector<int>(n,-1));
        return dfs(s,t,0,0,memo);
    }
};

int main() {
    Solution sol;
    cout << sol.numDistinct("xxyxy","xy");
    return 0;
}