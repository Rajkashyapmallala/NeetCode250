#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    static int numSquares(int n) {
        int s = sqrt(n);
        vector<vector<int>> dp(n+1,vector<int>(s+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i][j] = 1 + dp[i-j*j][j];
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }

        return dp[n][s];
    }
};
int main() {
    Solution::numSquares(13);
    return 0;
}